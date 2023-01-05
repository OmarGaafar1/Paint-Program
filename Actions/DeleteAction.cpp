#include "DeleteAction.h"
#include"../ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager* p) :Action(p)
{}

void DeleteAction::ReadActionParameters()
{
	SelectedFigs = pManager->ReturnSelectedFigures();
	Total_selected_Figures = pManager->GetSelectedFigCount();
}

void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	//pOut->PrintMessage(to_string(Total_selected_Figures));
	if (Total_selected_Figures == 0)// There is no selected figures
	{
		pOut->PrintMessage("No Selected Figure, Please Select a figure");
	}
	else
	{
		for (int i = 0; i < Total_selected_Figures; i++)
		{
			pManager->AddOperation(-1, SelectedFigs[i]); // for undo
			pManager->RemoveFigure(SelectedFigs[i]);

		}
		pManager->ClearSelectedFigs();
		pOut->PrintMessage("Figure(s) Deleted");
	}
}