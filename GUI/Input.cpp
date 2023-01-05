#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_EXIT: return EXIT;
				// Recently Added 
			case ITM_Move: return Move;
			case ITM_Circ: return Draw_Circle;
			case ITM_Triangle:return Draw_Triangle;
			case ITM_Square: return Draw_Square;
			case ITM_Hex:return Draw_Hex;
			case ITM_Play: return TO_PLAY;
			case ITM_Select: return Selection;
			case ITM_Redo:return Redo;
			case ITM_Undo: return Undo;
			case ITM_Delete: return Delete;
			case ITM_Clear: return Clear;
			case ITM_Start_rec: return Start_rec;
			case ITM_End_rec: return End_rec;
			case ITM_Play_Rec: return Play_Rec;
			case ITM_Save: return Save;
			case ITM_Load: return Load;
			case ITM_SOUND:return SOUND;
			case ITM_Changing_Drawing_color:return Change_Drawing_color;
			case ITM_Changing_Filling_color:return Change_filling_color;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_Draw: return TO_DRAW;
		case ITM_Pick_By_Type: return Pick_By_Type;
		case ITM_Pick_By_Color: return Pick_By_color;
		case ITM_Pick_By_Both: return Pick_By_Both;
		case ITM_Exit: return EXIT;


		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
