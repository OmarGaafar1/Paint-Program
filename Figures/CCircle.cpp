#include "CCircle.h"


CCircle::CCircle()
{
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Corner2 = P2;
	raduis = Distance(P1, P2);
}


void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCir(Center, raduis , FigGfxInfo, Selected);

}



bool CCircle::IsInsideFigure(int x, int y)const
{
	Point P;
	P.x = x;
	P.y = y;
	if (raduis >= sqrt(pow(Center.x- P.x,2) + pow(Center.y-P.y,2)))
	{
		return true;
	}
	return false;
}
void CCircle::Save(ofstream& OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << circ << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << DrawClr << '\t';
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
void CCircle::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Center.x >> Center.y >> Corner2.x >> Corner2.y;
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
	raduis = Distance(Center, Corner2);
}

void CCircle::PrintInfo(Output* pOut)
{
		string message = "Circle, ID: " + to_string(ID) + ", Center (" + to_string(Center.x) + "," + to_string(Center.y)
			+ "), Radius: " + to_string(int(raduis));
		pOut->PrintMessage(message);
	
}

int CCircle::ReturnType()
{
	return 1;
}

double CCircle::GetProperties(Point click, Point&, Point&)
{
	return raduis;
}

void CCircle::setRadius(double r)
{
	raduis = r;
}

