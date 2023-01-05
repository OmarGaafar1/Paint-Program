#pragma once

#include "Action.h"

class AddHexAction : public Action
{
private:
	Point P1; // Centre of the Hexagonal
	bool Voice;
	GfxInfo RectGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp,bool);

	//Reads Hexagonal parameters
	virtual void ReadActionParameters();

	//Add Hexagonal to the ApplicationManager
	virtual void Execute();

};