#pragma once
#include "Action.h" 



class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; //  Triangle corner
	GfxInfo RectGfxInfo;
	bool Voice;
public:
	AddTriangleAction(ApplicationManager* pApp,bool);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};