#include "CHexagonal.h"


CHexagonal::CHexagonal()
{
}

CHexagonal::CHexagonal(Point P1 , GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo)
{
	this->P1 = P1;
	P2.x = P1.x;
	P2.y = P1.y + 80;


	P3.x = P1.x - 50;
	P3.y = P1.y + 50;

	P4.x = P1.x - 50;
	P4.y = P1.y - 50;

	P5.x = P1.x;
	P5.y = P1.y - 80;

	P6.x = P1.x + 50;
	P6.y = P1.y - 50;

	P7.x = P1.x + 50;
	P7.y = P1.y + 50;
}
void CHexagonal::Draw(Output* pOut)const
{

	

	int X[] = { P2.x,P3.x,P4.x,P5.x,P6.x,P7.x };
	int Y[] = { P2.y,P3.y,P4.y,P5.y,P6.y,P7.y };

	int *ptr = &X[0];
	int *ptr2 = &Y[0];
	
	pOut->DrawHex(ptr, ptr2, FigGfxInfo, Selected);

}

bool CHexagonal::IsInsideFigure(int x, int y)const
{
	// we will divide the hexagonal into 2 tiangles top and bottom
	// and a rectangle in the middle
	//and we will check each part seperately to see if the point is inside it or not
	Point P;
	P.x = x;
	P.y = y;
	
	double Top_Triangle_area = Calc_Triangle_area(P2, P3, P7);
	double Area1 = Calc_Triangle_area(P, P3, P7);
	double Area2 = Calc_Triangle_area(P2, P, P7);
	double Area3 = Calc_Triangle_area(P2, P3, P);

	double Bottom_Traingle_area =  Calc_Triangle_area(P4, P5, P6);
	double Area4 = Calc_Triangle_area(P, P5, P6);
	double Area5 = Calc_Triangle_area(P4, P, P6);
	double Area6 = Calc_Triangle_area(P4, P5, P);

	if (Top_Triangle_area == Area1 + Area2 + Area3)
	{
		return true;
	}
	else if (Bottom_Traingle_area == Area4 + Area5 + Area6)
	{
		return true;
	}
	else
	{
		return ((x >= P3.x && x <= P6.x) || (x <= P3.x && x >= P6.x))
			&& ((y >= P3.y && y <= P6.y) || (y <= P3.y && y >= P6.y));
	}

}


double CHexagonal::Calc_Triangle_area(Point P1, Point P2 , Point P3)const
{
	return abs((P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y)) / 2.0);
}


void CHexagonal::Save(ofstream& OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << Hexagonal << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << DrawClr << '\t';
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
//virtual void PrintInfo(Output* pOut)const;
void CHexagonal::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawHex;
	string FillClr;
	InFile >> ID >> P1.x >> P1.y;
	InFile >> DrawHex;
	if (DrawHex == "")
	{
		//setting default to prevent error 
		DrawHex = "BLUE";
	}
	FigGfxInfo.DrawClr = getColorObject(DrawHex);
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

	P2.x = P1.x;
	P2.y = P1.y + 80;


	P3.x = P1.x - 50;
	P3.y = P1.y + 50;

	P4.x = P1.x - 50;
	P4.y = P1.y - 50;

	P5.x = P1.x;
	P5.y = P1.y - 80;

	P6.x = P1.x + 50;
	P6.y = P1.y - 50;

	P7.x = P1.x + 50;
	P7.y = P1.y + 50;

}

int CHexagonal::ReturnType()
{
	return 3;
}

double CHexagonal::GetProperties(Point click, Point&, Point&)
{
	return 0.0;
}

void CHexagonal::PrintInfo(Output* pOut)
{
	string message = "Hexagonal, ID: " + to_string(ID) + ", Center (" + to_string(P1.x) + "," + to_string(P1.y) + ")";
	pOut->PrintMessage(message);
}