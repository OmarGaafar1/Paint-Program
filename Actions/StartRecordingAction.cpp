#include "StartRecordingAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"
#include <set>


StartRecordingAction::StartRecordingAction(ApplicationManager* pApp):Action(pApp)
{
}

void StartRecordingAction::ReadActionParameters()
{

}

void StartRecordingAction::Execute()
{
	int CurrentlyDrawnFigs = pManager->getFigCount();
	int CurrentlySelectedFigs = pManager->GetSelectedFigCount();
	Output* pOut = pManager->GetOutput();
	if (CurrentlyDrawnFigs != 0 || CurrentlySelectedFigs != 0)
	{
		pOut->PrintMessage("This Action only can be done after a ClearAll action  or when program starts");
	}
	else
	{
		OutFile.open("Record.txt");
		pOut->PrintMessage("Recording in Progress , You have only 30 operation to record");
		
		
		
		ActionType Action;
		CFigure* const* SelectedFigs;
		int SelectedFigcount;
		CFigure* const* FigList;
		set<int> ids;
		CFigure* Fig;
		while (Operations < 30)
		{
			Action = pManager->GetUserAction();
				
			if (Action == End_rec) // User Clicks On Stop Rec Icon.
			{
				pOut->PrintMessage("Recording Stopped! ");
				break;
			}
			else if (Action == Start_rec || Action == Save || Action == Load || Action == EXIT || Action == STATUS)
			{
				// donot count these action as  operations
				Operations--;
			}
			else if (Action == Selection)
			{
				pManager->ExecuteAction(Action);
				pManager->UpdateInterface();
				do
				{
					Action = pManager->GetUserAction();
					if (Action != Selection)
					{
						SelectedFigs = pManager->ReturnSelectedFigures();
						SelectedFigcount = pManager->GetSelectedFigCount();
						for (int i = 0; i < SelectedFigcount; i++)
						{
							ids.insert(SelectedFigs[i]->Get_ID());
						}
						if (Action == Delete)
						{
							for (int i = 0; i < SelectedFigcount; i++)
							{
								SelectedFigs[i]->SaveFigByID(OutFile, SelectedFigs[i]->Get_ID());

							}
						}
					}
					pManager->ExecuteAction(Action);
					pManager->UpdateInterface();
						
						
				} while (Action == Selection);
					
					// get the ids for the selected figs.
					
					if (Action == Change_Drawing_color || Action == Change_filling_color)
					{
						SelectedFigs = pManager->ReturnSelectedFigures();
						FigList = pManager->ReturnFigList();
						for (int i = 0; i < pManager->getFigCount(); i++)
						{
							int id = FigList[i]->Get_ID();
							if (ids.count(id) > 0) // id found
							{
								FigList[i]->Save(OutFile);
							}
						}
					}
					
					
			}
			else if (Action == Draw_Circle || Action == Draw_Hex || Action == DRAW_RECT ||
				Action == Draw_Square || Action == Draw_Triangle)
				{
					pManager->ExecuteAction(Action);
					Fig = pManager->ReturnLastFigure();
					if (Fig != NULL)
					{
						Fig->Save(OutFile);
					}
				}
			else
			{
				continue;
			}
				
				pManager->UpdateInterface();
				Operations++;
				pOut->PrintMessage("You Have done " + to_string(Operations) + " Operations , You can click stop anytime");

		}
		if (Operations ==30)
		{
			pOut->PrintMessage("You Have Reached 30 Operation ):");
		}


	}
	OutFile.close();

	
}


