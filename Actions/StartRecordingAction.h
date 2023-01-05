#pragma once

#include "Action.h"
#include<fstream>

class StartRecordingAction :public Action
{
private:
	ofstream OutFile;
	
	int SelectedFigcount;
	
	int Operations = 0;

public:
	StartRecordingAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	
};
