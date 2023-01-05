#pragma once

#include "Action.h"

class AddSquareAction : public Action
{
private:
	Point P1; // Centre of the Square
	bool Voice;
	GfxInfo RectGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp,bool);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

};