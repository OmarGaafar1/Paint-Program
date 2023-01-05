#include "SelectionAction.h"

#include"../ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <iostream>
using namespace std;

SelectionAction::SelectionAction(ApplicationManager *P): Action(P)
{}

void SelectionAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure: Click a figure");

	//Read clicked point and store in P
	pIn->GetPointClicked(P.x, P.y);

	//Clear the status bar
	pOut->ClearStatusBar();
}

void SelectionAction::Execute()
{
	ReadActionParameters();

	Output* p = pManager->GetOutput();


	
	SelectedFig = pManager->GetFigure(P.x, P.y);
	CFigure* x = pManager->ReturnLastSelectedFig();
	if (x == SelectedFig || pManager->GetSelectedFigCount() == 0)
	{
		if (SelectedFig != NULL)
		{
			if (SelectedFig->IsSelected())
				Unselect();
			else
				Select();
		}
		
	}
	else
	{
		x->SetSelected(0);
		pManager->RemoveSelectedFigure(x);
		if (SelectedFig != NULL)
		{
			if (SelectedFig->IsSelected())
				Unselect();
			else
				Select();
		}
	}

	

}

void SelectionAction::Select()
{
	SelectedFig->SetSelected(1);
	pManager->AddSelectedFigure(SelectedFig);
	// un-comment when printInfo is working
	
	Output* pOut = pManager->GetOutput(); //Get a Pointer to the Output Interface
	SelectedFig->PrintInfo(pOut); //Print the selected figure info on the status bar
}

void SelectionAction::Unselect()
{
	SelectedFig->SetSelected(0); // false
	pManager->RemoveSelectedFigure(SelectedFig);
	
	Output* pOut = pManager->GetOutput(); //Get a Pointer to the Output Interface
	SelectedFig->PrintInfo(pOut); //Print the selected figure info on the status bar
}