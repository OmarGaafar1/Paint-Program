#include "AddHexAction.h"
#include"..\Figures\CHexagonal.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddHexAction::AddHexAction(ApplicationManager* pApp,bool voice) :Action(pApp),Voice(voice)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagonal: Click the center");
	if (Voice)
		PlaySound(TEXT("Sounds\\Hexagonal.wav"), NULL, SND_ASYNC);
	
	pIn->GetPointClicked(P1.x, P1.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddHexAction::Execute()
{
	ReadActionParameters();
	
	CFigure *R = new CHexagonal(P1 , RectGfxInfo);

	pManager->AddFigure(R);
	pManager->AddOperation(0, R);



}