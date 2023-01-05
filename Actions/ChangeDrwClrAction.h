#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"
class ChangeDrwClrAction :public Action
{
private:
	color InputClr;
	int selectedCount; //number of selected figures
	CFigure* const* SelectedFigs; //pointer to selected figures

public:
	ChangeDrwClrAction(ApplicationManager* pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();


};

