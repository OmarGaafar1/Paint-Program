#pragma once

#include"CFigure.h"

class CSquare : public CFigure
{
private:
	Point center;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut)const ;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual int ReturnType();
	double GetProperties(Point click, Point&, Point&);

};