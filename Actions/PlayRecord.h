#pragma once

#include "Action.h"
#include<fstream>

class PlayRecordAction :public Action
{
private:
	ifstream InputFile;
	int NumOfFigs = 0; 

public:
	PlayRecordAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();

};
