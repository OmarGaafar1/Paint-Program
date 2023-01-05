#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"

class UndoAction :public Action
{
private:
public:
	UndoAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();

};
