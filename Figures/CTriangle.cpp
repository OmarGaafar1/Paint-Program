#include "CTriangle.h"


double CTriangle::Calc_Area(Point P1, Point P2, Point P3)const
{
	return abs((P1.x * (P2.y -P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y)) / 2.0);
}

CTriangle::CTriangle()
{
}

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a tri on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

bool CTriangle::IsInsideFigure(int x, int y)const
{
	// we have triangle ABC and a point p
	// if Area (PAB) + Area(APC) + Area(ABP) = Area(ABC)
	// Then point P is inside the triangle
	Point P;
	P.x = x;
	P.y = y;

	double TriangleArea = Calc_Area(Corner1, Corner2, Corner3);

	double Area1 = Calc_Area(P, Corner2, Corner3);
	double Area2 = Calc_Area(Corner1, P, Corner3);
	double Area3 = Calc_Area(Corner1, Corner2, P);



	if (TriangleArea == (Area1 + Area2 + Area3))
	{
		return true;
	}
	return false;


}

void CTriangle::Save(ofstream& OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << triangle << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << Corner3.x << '\t' << Corner3.y << '\t' << DrawClr << '\t';
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
void CTriangle::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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
int CTriangle::ReturnType()
{
	return 4;
}
double CTriangle::GetProperties(Point click, Point&, Point&)
{
	return 0.0;
}
void CTriangle::PrintInfo(Output* pOut)
{
	string message = "Triangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner 3: (" + to_string(Corner3.x)
		+ "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(message);
}
