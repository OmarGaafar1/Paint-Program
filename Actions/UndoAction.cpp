#include "UndoAction.h"
#include"../ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
UndoAction::UndoAction(ApplicationManager* p) :Action(p)
{}

void UndoAction::ReadActionParameters()
{

}

void UndoAction::Execute()
{
	
	Output* pOut = pManager->GetOutput();
	int operationsCount = pManager->Get_OperationCount();
	if (operationsCount == 0 )
	{
		pOut->PrintMessage("There is nothing Done to undo :)");
	}
	else
	{
		pair <int, CFigure*> Operation = pManager->ReturnLastOperation();
		int type = Operation.first;
		CFigure* LastFig = Operation.second;
		int OperationsCount = pManager->Get_OperationCount();
		int UndoCount = pManager->GetUndoCount();
		if (UndoCount == 5)
		{
			pManager->SetUndoCount(0);
		}
		if (type == -1) // this means that this fig was deleted by the user
		{

			pManager->AddFigure(LastFig);
			pManager->RemoveLastOperation();
			pManager->AddUndoFig(-1,LastFig,BLACK);

		}
		else
		{
			if (LastFig->ISFilled())
			{
				color s = LastFig->GetGfxInfo().FillClr;
				pManager->AddUndoFig(0,LastFig,s);

				LastFig->SetFigUnFilled();

			}
			else if (LastFig->GetGfxInfo().DrawClr != BLUE)
			{
				color s = LastFig->GetGfxInfo().DrawClr;
				pManager->AddUndoFig(1,LastFig,s);
				LastFig->ChngDrawClr(BLUE);
			}
			else
			{
				pManager->AddUndoFig(3,LastFig,BLACK);
				pManager->RemoveFigure(LastFig);
				pManager->RemoveLastOperation();

			}
		}

	}
	
	
}