#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu

	// Recently Added 
	ITM_Square,  // Square Item In Menu

	ITM_Circ, // Circle Item in menu

	ITM_Triangle, // Triangle Item In Menu
	ITM_Hex,  // Hexagonal Item In Menu
	ITM_Select,
	ITM_Changing_Drawing_color,
	ITM_Changing_Filling_color,
	ITM_Redo,
	ITM_Undo,
	ITM_Delete,
	ITM_Clear,
	ITM_Start_rec,
	ITM_End_rec,
	ITM_Play_Rec,
	ITM_Save,
	ITM_Load,
	ITM_Move,
	ITM_Play,
	ITM_SOUND,
	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT	//no. of menu items ==> This should be the last line in this enum
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here

	ITM_Pick_By_Type,
	ITM_Pick_By_Color,
	ITM_Pick_By_Both,

	ITM_Draw,
	ITM_Exit,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	
	bool isFilled;
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool Sound;
	/// Add more members if needed
	
}UI;	//create a global object UI

#endif