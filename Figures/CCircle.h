#pragma

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Corner2;
	double raduis;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y)const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual int  ReturnType();
	double GetProperties(Point click, Point&, Point&);
	void setRadius(double);

	


};

