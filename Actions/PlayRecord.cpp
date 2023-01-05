#include "PlayRecord.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

#include <string>
#include"../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
#include"../Figures/CCircle.h"
#include "../Figures/CHexagonal.h"

#include <chrono>
#include <thread>



using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp):Action(pApp)
{
}
void PlayRecordAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("The Record Will Start.... ");
	InputFile.open("Record.txt");
	string str;
	while (getline(InputFile, str))
	{
		// counts how many object in the file;
		NumOfFigs++;
	}
	InputFile.close();
}

void PlayRecordAction::Execute()
{
	
	ReadActionParameters();
	pManager->RemoveAllFigures();
	pManager->UpdateInterface();
	InputFile.open("Record.txt");

	CFigure* pFig;
	for (int i = 0; i < NumOfFigs; i++)//for loop to make object of each shape
	{
		int shapeType;
		InputFile >> shapeType;
		if (shapeType == -1)
		{
			// This mean we need to delete it
			int ID;
			InputFile >> ID;
			pManager->RemoveFigureByID(ID);
			sleep_for(1s);
			pManager->UpdateInterface();
			continue;
		}
		switch (shapeType)// switch case to make object of each shape if it is already saved before
		{
		case rect:
			pFig = new CRectangle;
			break;
		case square:
			pFig = new CSquare;
			break;

		case triangle:
			pFig = new CTriangle;
			break;

		case circ:
			pFig = new CCircle;
			break;
		case Hexagonal:
			pFig = new CHexagonal;
			break;
		default:
			pFig = NULL;
			break;
		}
		//loading the parameters of each figure 
		if (pFig != NULL)
		{
			pFig->Load(InputFile);
			pManager->AddFigure(pFig); //send to applocation manager to add the shape
			sleep_for(1s);
			pManager->UpdateInterface();
		}
	}
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("The Record has ended!");


}
