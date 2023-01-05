#pragma once

#include "Action.h"
//Add Circle Action class
class AddCircleAction : public Action
{
private:
	Point P1; //Circle Corners
	Point P2;
	bool Voice;
	GfxInfo RectGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp,bool);	

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

