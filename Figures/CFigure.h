#ifndef CFIGURE_H
#define CFIGURE_H
#include<fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool PlayHidden;
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	 // function to calculate the distance between two points.
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	double Distance(Point, Point);
	GfxInfo GetGfxInfo()const;
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	void Set_ID(int id);
	int  Get_ID();
	void SaveFigByID(ofstream& Outfile, int id);

	bool ISFilled(); // show if the fig is filled or not 
	void SetFigUnFilled();
	virtual bool IsInsideFigure(int x, int y) const=0;		
	
	string getColorName(color)const;
	color getColorObject(string)const;

	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	virtual int ReturnType() = 0;
	virtual double GetProperties(Point click, Point&, Point&) = 0;
												// the object or not.



	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	void Hide();					//Hides figures in playmode.
	void Show();					//Shows figures in playmode.
	bool HiddenStatus();
};

#endif