#pragma once

#include "Action.h"

class ClearAllAction :public Action
{
private:
public:
	ClearAllAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	
};
