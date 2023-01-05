#include "ApplicationManager.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddHexAction.h"
#include "Actions/AddCircleAction.h"
#include "Actions/AddTriangleAction.h"
#include"Actions/SelectionAction.h"
#include"Actions/DeleteAction.h"
#include"Actions/ChangeFillClr.h"
#include"Actions/ChangeDrwClrAction.h"
#include "Actions/AddSaveAction.h"
#include"Actions/AddLoadAction.h"
#include"Actions/ClearAllAction.h"
#include "Actions/StartRecordingAction.h"
#include"Actions/PlayRecord.h"
#include "Actions/AddPlayAction.h"
#include "Actions/PickByType.h"
#include "Actions/PickByColor.h"
#include "Actions/PickByBoth.h"
#include "Actions/UndoAction.h"
#include "Actions/Redo.h"
#include "Actions/Sound.h"
#include "Actions/Move.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	ON_OFF_SOUND = 1;
	FigCount = 0;
	selectedCount = 0;
	UndoCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < 5; i++)
	{
		Operations.push_back({ 0,NULL });
	}
	REDO a;
	a.Cl = BLACK;
	a.type = 0;
	for (int i = 0; i < 5; i++)
	{
		UndoFigs.push_back({ a,NULL });
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this, ON_OFF_SOUND);
			break;
		case Draw_Square:
			pAct = new AddSquareAction(this, ON_OFF_SOUND);
			break;
		case Draw_Hex:
			pAct = new AddHexAction(this, ON_OFF_SOUND);
			break;
		case Draw_Circle:
			pAct = new AddCircleAction(this, ON_OFF_SOUND);
			break;
		case Draw_Triangle:
			pAct = new AddTriangleAction(this, ON_OFF_SOUND);
			break;
		case Selection:
			pAct = new SelectionAction(this);
			break;
		case Delete:
			pAct = new DeleteAction(this);
			break;
		case Change_filling_color:
			pAct = new ChangeFillClrAction(this);
			break;
		case Change_Drawing_color:
			pAct = new ChangeDrwClrAction(this);
			break;
		case Save:
			pAct = new AddSaveAction(this);
			break;
		case Load:
			pAct = new AddLoadAction(this);
			break;
		case Clear:
			pAct = new ClearAllAction(this);
			break;
		case Start_rec:
			pAct = new StartRecordingAction(this);
			break;
		case Play_Rec:
			pAct = new PlayRecordAction(this);
			break;
		case TO_PLAY:
			pAct = new AddPlayAction(this);
			break;
		case Pick_By_Type:
			pAct = new PickByType(this);
			break;
		case Pick_By_color:
			pAct = new PickByColor(this);
			break;
		case Pick_By_Both:
			pAct = new PickByBoth(this);
			break;
		case TO_DRAW:
			pOut->CreateDrawToolBar();
			break;
		case Undo:
			pAct = new UndoAction(this);
			break;
		case Redo:
			pAct = new RedoAction(this);
			break;
		case SOUND:
			pAct = new Sound(this, &ON_OFF_SOUND);
			break;
		case Move:
			pAct = new MoveAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
void ApplicationManager::GetColor(color& Final_clr)
{
	pOut->PrintMessage("Press 1:Red , Press2 :Blue ,Press 3: Black, Press 4: Green , Press 5 White -- Worng inputs--> Black Color");
	string Color  = pIn->GetSrting(pOut);
	if (Color.length() >1 || !isdigit(Color[0]))
	{
		Final_clr = BLACK;//Default color
		pOut->ClearStatusBar();
		return;
	}
	pOut->ClearStatusBar();
	int choice = stoi(Color);
	string Final_color;

	if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
	{
		switch (choice)
		{
		case 1:
			Final_clr = RED;
			break;

		case 2:
			Final_clr = BLUE;
			break;

		case 3:
			Final_clr = BLACK;
			break;
		case 4:
			Final_clr = GREEN;
			break;
		case 5:
			Final_clr = WHITE;
			break;
		default:
			break;
		}
	}
	else
	{
		Final_clr = BLACK;//Default color
	}
	
	
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		pFig->Set_ID(FigCount);
		FigCount++;
	}
}

// add a figure to the selected figures
void ApplicationManager::AddSelectedFigure(CFigure* p) {

	SelectedFigs[selectedCount] = p;
	selectedCount++;
}

void ApplicationManager::RemoveSelectedFigure(CFigure* s)
{
	// looping through all the selected figures and if the figure is found we will remove it
	// and shifting all the array to the left
	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigs[i] == s) {
			SelectedFigs[i] = SelectedFigs[selectedCount - 1];
			SelectedFigs[selectedCount - 1] = NULL;
			selectedCount--;
			return;
		}
	}
}




CFigure* const* ApplicationManager::ReturnSelectedFigures()
{
	return SelectedFigs;
}
CFigure* const* ApplicationManager::ReturnFigList()
{
	return FigList;
}

int ApplicationManager::GetSelectedFigCount()const
{
	return selectedCount;
}
void ApplicationManager::ClearSelectedFigs()
{
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigs[i] = NULL;
	}
	selectedCount = 0;
}
void ApplicationManager::RemoveFigure(CFigure* s)
{
	bool flag = false;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == s || flag)
		{
			FigList[i] = FigList[i + 1];
			flag = true;
		}
	}
	FigCount--;
	FigList[FigCount] = NULL;
}
void ApplicationManager::RemoveFigureByID(int ID)
{

	bool flag = false;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->Get_ID() == ID || flag)
		{
			FigList[i] = FigList[i + 1];
			flag = true;
		}
	}
	FigCount--;
	FigList[FigCount] = NULL;

}
void ApplicationManager::RemoveAllFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = NULL;
	}
	FigCount = 0;
}
CFigure* ApplicationManager::ReturnLastSelectedFig()
{
	return SelectedFigs[selectedCount - 1];
}
void ApplicationManager::RemoveLastFigure()
{
	FigList[FigCount - 1] = NULL;
	FigCount--;
}
void ApplicationManager::AddUndoFig(int i ,CFigure *p, color s)
{
	UndoFigs[UndoCount].first.type = i;
	UndoFigs[UndoCount].first.Cl = s;
	UndoFigs[UndoCount].second = p;
	UndoCount++;
}

pair<REDO,CFigure*> ApplicationManager::ReturnAndRemoveLastUndo()
{

	return UndoFigs[--UndoCount];

}

int ApplicationManager::GetUndoCount()
{
	return UndoCount;
}
CFigure* ApplicationManager::ReturnLastFigure()
{
	return FigList[FigCount-1];

}
void ApplicationManager::AddOperation(int i , CFigure* fig)
{
	
	if (operationsCount == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			Operations[i] = Operations[i + 1];

		}
		Operations[4] = { i,fig };
	}
	else
	{
		Operations[operationsCount] = { i,fig };
		operationsCount++;
	}

}
void ApplicationManager::RemoveLastOperation()
{
	operationsCount--;
}
int ApplicationManager::Get_OperationCount()
{
	return operationsCount;
}
void ApplicationManager::set_LastMessage(string s)
{
	LastMessage = s;
}
void ApplicationManager::SetUndoCount(int i )
{
	UndoCount = i;
}

void ApplicationManager::ClearAllOperation()
{
	for (int i = 0; i < 5; i++)
	{
		Operations[i].first = 0;
		Operations[i].second = NULL;
	}
	operationsCount = 0;
}

void ApplicationManager::ClearUNDO()
{
	UndoCount = 0;
}



pair <int, CFigure*>ApplicationManager::ReturnLastOperation()
{
	return Operations[operationsCount - 1];

}



////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	// looping through all figures and if the selected point is found inside any figure
	// we will retur a pointer to it.
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList == NULL)
			continue;
		if (FigList[i]->IsInsideFigure(x, y))
			{
				return FigList[i];
			}
	}


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == NULL)
		{
			continue;
		}
		if (FigList[i]->HiddenStatus() == false)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}		//Call Draw function (virtual member fn)
	
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::SaveAll(ofstream& OutFile)
{
	//Loop on each figure ,then saving it 
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}

int ApplicationManager::getFigCount() const
{
	return FigCount;
}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	ClearSelectedFigs();
}

CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
