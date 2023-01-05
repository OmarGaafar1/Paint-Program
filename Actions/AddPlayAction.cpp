#include "AddPlayAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Output.h"

AddPlayAction::AddPlayAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddPlayAction::Execute() {

	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("This is Play Mode");
}