#include"CSquare.h"


#include <iostream>
using namespace std;
CSquare::CSquare()
{
}

CSquare::CSquare(Point p1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = p1;
}
Point P2, P3, P4, P5;
void CSquare::Draw(Output* pOut)const 
{
	
	P2.x = center.x - 60;
	P2.y = center.y + 60;

	P3.x = center.x - 60;
	P3.y = center.y - 60;

	P4.x = center.x + 60;
	P4.y = center.y - 60;

	P5.x = center.x + 60;
	P5.y = center.y + 60;

	int X_cordinates[] = { P2.x,P3.x,P4.x,P5.x };
	int Y_cordinates[] = { P2.y,P3.y,P4.y,P5.y };

	int *ptr = &X_cordinates[0];
	int *ptr2 = &Y_cordinates[0];
	
	pOut->DrawSquare(ptr, ptr2, FigGfxInfo, Selected);
}

bool CSquare::IsInsideFigure(int x, int y) const
{
	return ((x >= P3.x && x <= P5.x) || (x <= P3.x && x >= P5.x))
		&& ((y >= P3.y && y <= P5.y) || (y <= P3.y && y >= P5.y));
}

void CSquare::Save(ofstream& OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << square << '\t' << ID << '\t' << center.x <<  '\t'<< center.y << '\t' << DrawClr << '\t';
	//if filled save the fill clr
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = getColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CSquare::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawSquare;
	string FillClr;
	InFile >> ID >> center.x >> center.y;
	InFile >> DrawSquare;
	if (DrawSquare == "")
	{// to prevent files error 
		DrawSquare = "BLUE";
	}

	FigGfxInfo.DrawClr = getColorObject(DrawSquare);
	InFile >> FillClr;
	cout << "Fill clr = " << FillClr << endl;
	//if filled set the fill clr
	if (FillClr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObject(FillClr);
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
}
void CSquare::PrintInfo(Output* pOut)
{
	string message = "Square, ID: " + to_string(ID) + ", Center (" + to_string(center.x) + "," + to_string(center.y)+ ")";
	pOut->PrintMessage(message);
}

int CSquare::ReturnType()
{
	return 0;
}

double CSquare::GetProperties(Point click, Point&, Point&)
{
	return 0.0;
}

