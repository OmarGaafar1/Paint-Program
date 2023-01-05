#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp,bool voice) :Action(pApp),Voice(voice) // constructor 
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click the center ponit");
	if (Voice)
		PlaySound(TEXT("Sounds\\Squaree.wav"), NULL, SND_ASYNC);
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CSquare* R = new CSquare(P1, RectGfxInfo);
	

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	pManager->AddOperation(0, R);


}