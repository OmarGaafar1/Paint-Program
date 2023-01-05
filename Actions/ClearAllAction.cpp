#include "ClearAllAction.h"
#include"../ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp):Action (pApp)
{

}

void ClearAllAction::ReadActionParameters()
{
}


void ClearAllAction::Execute()
{
	
	pManager->ClearSelectedFigs();
	pManager->RemoveAllFigures();
	pManager->ClearAllOperation();
	pManager->ClearUNDO();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Clear Done !");
	
}
