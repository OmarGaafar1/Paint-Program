#include "Move.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "../Figures/CCircle.h"
#include"../Figures/CHexagonal.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"


MoveAction::MoveAction(ApplicationManager*pApp):Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
}

void MoveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();
	
	int selectedCount = pManager->GetSelectedFigCount();
	if (selectedCount == 0)
	{
		pOut->PrintMessage("No Selectedf Figure");
	}
	else if (selectedCount > 1)
	{
		pOut->PrintMessage("You can only move 1 Figure at once :)");
	}
	else
	{
		Point p;
		pOut->PrintMessage("Select a point to move the figure ");
		pIn->GetPointClicked(p.x, p.y);
		CFigure* Fig = pManager->ReturnLastSelectedFig();
		pManager->RemoveFigure(Fig);
		pManager->RemoveSelectedFigure(Fig);
		int figType = Fig->ReturnType();
		GfxInfo IFX;
		IFX = Fig->GetGfxInfo();
		Point P1, P2;
		if (figType == 0)
		{
			CSquare* Fig = new CSquare(p, IFX);
			pManager->AddFigure(Fig);
		}
		else if (figType == 1)
		{
			double raduis = Fig->GetProperties(p,P1,P2);
			CCircle* n = new CCircle(p, p, IFX);
			n->setRadius(raduis);
			pManager->AddFigure(n);
		}
		else if (figType == 2)
		{
			
			Fig->GetProperties(p, P1, P2);
			CRectangle* n = new CRectangle(P1, P2, IFX);
			pManager->AddFigure(n);
		}
		else if (figType == 3)
		{
			CHexagonal* Fig = new CHexagonal(p, IFX);
			pManager->AddFigure(Fig);
		}
		else if (figType == 4)
		{
			// 
		}
		delete Fig;
	}
	pManager->ClearSelectedFigs();
}
