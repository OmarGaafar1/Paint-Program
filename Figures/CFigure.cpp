#include "CFigure.h"

CFigure::CFigure()
{

	Selected = false;
	PlayHidden = false;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	PlayHidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::Set_ID(int id)
{
	ID = id;
}

int CFigure::Get_ID()
{
	return ID;
}

void CFigure::SaveFigByID(ofstream& Outfile, int id)
{
	
		Outfile << "-1" << "\t" << id << endl;
}

bool CFigure::ISFilled()
{
	return FigGfxInfo.isFilled;
}

void CFigure::SetFigUnFilled()
{
	this->FigGfxInfo.isFilled = false;
}

double CFigure::Distance(Point P1, Point P2)
{
	return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
}

string CFigure::getColorName(color name)const
{

	if (name == RED)
	{
		return "RED";
	}

	if (name == BLACK)
	{
		return "BLACK";
	}

	if (name == BLUE)
	{
		return "BLUE";
	}

	if (name == GREEN)
	{
		return "GREEN";
	}

	if (name == WHITE)
	{
		return "WHITE";
	}
}

color CFigure::getColorObject(string name)const
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

//Hides Figures
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}

bool CFigure::HiddenStatus()
{
	return PlayHidden;
}

GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}