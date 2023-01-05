#pragma

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual int  ReturnType();
	double GetProperties(Point click , Point& , Point&);

};

