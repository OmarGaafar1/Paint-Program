#include "Redo.h"
#include"../ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
RedoAction::RedoAction(ApplicationManager* pApp):Action (pApp)
{
}

void RedoAction::ReadActionParameters()
{
}

void RedoAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	int undoCount = pManager->GetUndoCount();
	if (undoCount == 0)
	{
		pOut->PrintMessage("There Is Nothing to Redo");
	}
	else
	{
		pair<REDO, CFigure*> Operation = pManager->ReturnAndRemoveLastUndo();

		int type = Operation.first.type;
		CFigure* Fig = Operation.second;
		color s = Operation.first.Cl;


		if (type == 0)
		{
			Fig->ChngFillClr(s);
		}
		else if (type == 1)
		{
			Fig->ChngDrawClr(s);
		}
		else if (type == 3)
		{
			pManager->AddFigure(Fig);
		}
		else
		{
			pManager->RemoveFigure(Fig);
		}

		pManager->UpdateInterface();
	}
}
	
