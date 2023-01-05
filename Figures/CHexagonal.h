#pragma once
#include "CFigure.h"


class CHexagonal : public CFigure
{
private:
	Point P1 , P2, P3, P4, P5, P6, P7;

	double Calc_Triangle_area(Point, Point, Point)const;

public:
	CHexagonal();
	CHexagonal(Point P1, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void PrintInfo(Output* pOut);
	virtual void Load(ifstream& Infile);
	virtual int ReturnType();
	double GetProperties(Point click, Point&, Point&);
};