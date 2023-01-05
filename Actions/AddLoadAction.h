#pragma once
#include"Action.h"
#include <fstream>




class AddLoadAction :public Action
{
private:
	ifstream InputFile;
	string fileName;
	//utility function to get the name of the color in color type
	color getColorObject(string)const;
public:
	AddLoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
