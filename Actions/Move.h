#pragma once

#include"Action.h"

#include "../Figures/CFigure.h"
class MoveAction : public Action
{
private:
	

public:
	MoveAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute();
};
