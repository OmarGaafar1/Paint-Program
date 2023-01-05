#pragma once
#include "Action.h"

class AddPlayAction : public Action {
public:
	AddPlayAction(ApplicationManager* pApp);

	virtual void ReadActionParameters() {};
	virtual void Execute();
};
