#include "ChangeFillClr.h"

#include "../ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillClrAction::ChangeFillClrAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChangeFillClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Initialise local SelectedFigs and selectedCount 
	SelectedFigs = pManager->ReturnSelectedFigures();
	selectedCount = pManager->GetSelectedFigCount();

	pManager->GetColor(InputClr);// by refrence so the color will be copied into InputClr Variable
}

void ChangeFillClrAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Reads the input draw color
	ReadActionParameters();

	if (selectedCount == 0)
	{
		pOut->PrintMessage("NO Selected figures found!!");
	}
	else
	{
		for (int i = 0; i < selectedCount; i++)
		{
			SelectedFigs[i]->ChngFillClr(InputClr);
			pManager->AddOperation(0, SelectedFigs[i]);
			
		}
	}
	


}




