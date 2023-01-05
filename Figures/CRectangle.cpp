#include "CRectangle.h"


#include <iostream>
using namespace std;
CRectangle::CRectangle()
{
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInsideFigure(int x, int y)const
{

	return ((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x))
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}
void CRectangle::Save(ofstream& OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << rect << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << DrawClr << '\t';
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
void CRectangle::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	InFile >> FillClr;
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

int CRectangle::ReturnType()
{
	return 2 ;
}

double CRectangle::GetProperties(Point click, Point& P1, Point& P2)
{
	int height = Corner1.y - Corner2.y;
	int width = Corner1.x - Corner2.x;
	
	P1.x = click.x - (width / 2);
	P2.x = click.x + (width / 2);

	P1.y = click.y + (height / 2);
	P2.y = click.y - (height / 2);

	return 0.0;
}

void CRectangle::PrintInfo(Output* pOut)
{
	string message = "Rectangle, ID: " + to_string(ID) + ", Upper Point (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ ") Lower Point ( " + to_string(int(Corner2.x)) + ","+ to_string(Corner2.y) + ")";
	pOut->PrintMessage(message);
 }