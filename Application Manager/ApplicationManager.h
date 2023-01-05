#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <vector>
#include <tuple>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;						//Actual number of figures
	int operation_reset = 4;			// used for undo 
	CFigure* FigList[MaxFigCount];		//List of all figures (Array of pointers)
	CFigure* SelectedFigs[MaxFigCount]; //array of pointers to the selected figures
	vector<pair<int, CFigure*>> Operations; // initializing it in the constructor
	vector<pair<REDO,CFigure*>> UndoFigs;
	int selectedCount  ;					//Number of selected figures
	int UndoCount ;
	int operationsCount = 0;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	bool ON_OFF_SOUND;
	string LastMessage;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	void set_LastMessage(string);
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void GetColor(color &);
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* DrawnFigs(int) const;
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void AddSelectedFigure(CFigure *s);
	void RemoveSelectedFigure(CFigure*);
	CFigure* const* ReturnSelectedFigures();
	CFigure* const* ReturnFigList(); // return current drawn figs;

	int GetSelectedFigCount()const;
	void ClearSelectedFigs();
	void RemoveFigure(CFigure*);
	void RemoveFigureByID(int ID);
	void RemoveAllFigures(); // delete all figures

	CFigure* ReturnLastSelectedFig();

	// Unod-Redo
	void RemoveLastFigure();
	void AddUndoFig(int , CFigure* , color);
	pair<REDO,CFigure*> ReturnAndRemoveLastUndo();
	int GetUndoCount();
	void SetUndoCount(int);
	void ClearAllOperation();
	void ClearUNDO();
	void AddOperation(int, CFigure*);
	pair <int, CFigure*> ReturnLastOperation();
	void RemoveLastOperation();

	int Get_OperationCount();
	






	CFigure* ReturnLastFigure(); // used in startRecording Class

	int getFigCount() const;
	void ApplicationManager::SaveAll(ofstream& OutFile);
	void ApplicationManager::ClearFigList();
		

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif