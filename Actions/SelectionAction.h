#pragma once

#include "../Figures/CFigure.h"
#include "Action.h"

class SelectionAction :public Action
{
private:
	Point P;  //Clicked point
	CFigure* SelectedFig; //Clicked figure (NULL if no figure is clicked)
public:
	SelectionAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	void Select();
	void Unselect();
};