#pragma once

#include"Action.h"

#include "../Figures/CFigure.h"
class DeleteAction : public Action
{
private:
	int Removed_ID;
	CFigure* const* SelectedFigs;
	int Total_selected_Figures;

public:
	DeleteAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute();
};
