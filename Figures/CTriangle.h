#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	double Calc_Area(Point, Point, Point)const;
public:
	CTriangle();
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	
	virtual void Save(ofstream& OutFile);
	virtual void PrintInfo(Output* pOut);
	virtual void Load(ifstream& Infile);
	virtual int ReturnType();
	double GetProperties(Point click, Point&, Point&);

};

#endif