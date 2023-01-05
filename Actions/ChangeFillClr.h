#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"
class ChangeFillClrAction :public Action
{
private:
	color InputClr;
	int selectedCount; //number of selected figures
	CFigure* const* SelectedFigs; //pointer to selected figures

public:
	ChangeFillClrAction(ApplicationManager* pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();


};
