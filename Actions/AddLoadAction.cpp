#include"AddLoadAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

#include"../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
#include"../Figures/CCircle.h"
#include "../Figures/CHexagonal.h"


AddLoadAction::AddLoadAction(ApplicationManager* pApp) :Action(pApp)
{
}



//Read Parameters for the load action
void AddLoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Enter Name of the file you want to load");


	fileName = pIn->GetSrting(pOut) + ".txt";
	
	InputFile.open(fileName);//open file
	pOut->ClearDrawArea();//clear drawing area
	
	if (InputFile.is_open())//check if file exist or not
	{
		pOut->PrintMessage("Your file has been successfully loaded");
	}
	else { pOut->PrintMessage("No file found with name: " + fileName); }
}

//Execute action Load Action
void AddLoadAction::Execute()
{
	CFigure* pFig = NULL;//to create object of each figure
	int numberOfFiguers; //count number of figures
	string DrawClr;//with color or not
    string FillClr;
	ReadActionParameters();
	
	if (InputFile.is_open())//check if the file is opened or not
	{

		InputFile >> DrawClr; //check if there is colors or not
		UI.DrawColor = getColorObject(DrawClr);//get the color of figure
		
		InputFile >> FillClr;
		UI.FillColor = getColorObject(FillClr);//is filled or not
		InputFile >> numberOfFiguers;//count nnum of figures
		
		pManager->ClearFigList();//cleaning the figlist before loading the file
		for (int i = 0; i < numberOfFiguers; i++)//for loop to make object of each shape
		{
			int shapeType;
			InputFile >> shapeType;
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
			pFig->Load(InputFile);
			if (pFig != NULL)
			{
				pManager->AddFigure(pFig); //send to applocation manager to add the shape
			}
		}
	
		
		InputFile.close();//close file at the end
	}
}
//function that get a string clr name returning a clr obj
color AddLoadAction::getColorObject(string name)const
{
	if (name == "RED")
	{
		return RED;
	}

	if (name == "BLACK")
	{
		return BLACK;
	}

	if (name == "BLUE")
	{
		return BLUE;
	}

	if (name == "GREEN")
	{
		return GREEN;
	}

	if (name == "WHITE")
	{
		return WHITE;
	}

}
