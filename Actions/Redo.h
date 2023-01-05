#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"

class RedoAction :public Action
{
private:
public:
	RedoAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();

};
