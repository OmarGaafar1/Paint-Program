#include "PickByBoth.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagonal.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



void PickByBoth::PrntScore(int S)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (S == 1)
	{
		rigSel++;
		message = "Right!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else 	if (S == 2)
	{
		wrgSel++;
		message = "Wrong!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	pOut->PrintMessage(message);


}

PickByBoth::PickByBoth(ApplicationManager* pApp) :Action(pApp)
{
	no_combs = 0;
	wrgSel = 0;
	rigSel = 0;
	for (int i = 0; i < 30; i++)
		combinations[i] = 0;
}


PickByBoth::~PickByBoth()
{

}

void PickByBoth::ReadActionParameters()
{
	for (int i = 0; i < pManager->getFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);
		if ((Fig->GetGfxInfo().isFilled) ) //counts combinations occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[0]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[1]++;
				else if (dynamic_cast<CHexagonal*>(Fig))
					combinations[2]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[25]++;
				else // cirlce
					combinations[3]++;
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[4]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[5]++;
				else if (dynamic_cast<CHexagonal*>(Fig))
					combinations[6]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[26]++;
				else
					combinations[7]++;
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[8]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[9]++;
				else if (dynamic_cast<CHexagonal*>(Fig))
					combinations[10]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[27]++;
				else
					combinations[11]++;
			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[12]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[13]++;
				else if (dynamic_cast<CHexagonal*>(Fig))
					combinations[14]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[28]++;
				else
					combinations[15]++;
			}
			else
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[16]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[17]++;
				else if (dynamic_cast<CHexagonal*>(Fig))
					combinations[18]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[29]++;
				else
					combinations[19]++;
			}
		}
		else {
			if (dynamic_cast<CRectangle*>(Fig))
				combinations[20]++;
			else if (dynamic_cast<CTriangle*>(Fig))
				combinations[21]++;
			else if (dynamic_cast<CHexagonal*>(Fig))
				combinations[22]++;
			else if (dynamic_cast<CCircle*>(Fig))
				combinations[23]++;
			else if (dynamic_cast<CSquare*>(Fig))
				combinations[24]++;
		}
	}

	for (int i = 0; i < 30; i++)
		if (combinations[i] != 0)
			no_combs++;


}

void PickByBoth::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (no_combs > 1)
	{
		//Figure to be hidden
		CFigure* clickedFig;
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);
		if ((Fig->GetGfxInfo().isFilled))
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[0];
					pOut->PrintMessage("Pick up all the black rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[1];
					pOut->PrintMessage("Pick up all the black triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[25];
					pOut->PrintMessage("Pick up all the black Squares");

				}
				else if (dynamic_cast<CHexagonal*>(Fig))
				{
					picked_comb_no = combinations[2];
					pOut->PrintMessage("Pick up all the black Hexagonals");

				}
				else
				{
					picked_comb_no = combinations[3];
					pOut->PrintMessage("Pick up all the black circles!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[4];
					pOut->PrintMessage("Pick up all the white rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[5];
					pOut->PrintMessage("Pick up all the white triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[26];
					pOut->PrintMessage("Pick up all the white Squares");

				}
				else if (dynamic_cast<CHexagonal*>(Fig))
				{
					picked_comb_no = combinations[6];
					pOut->PrintMessage("Pick up all the white Hexagonals");

				}
				else
				{
					picked_comb_no = combinations[7];
					pOut->PrintMessage("Pick up all the white circles!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[8];
					pOut->PrintMessage("Pick up all the blue rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[9];
					pOut->PrintMessage("Pick up all the blue triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[27];
					pOut->PrintMessage("Pick up all the blue Squares");

				}
				else if (dynamic_cast<CHexagonal*>(Fig))
				{
					picked_comb_no = combinations[10];
					pOut->PrintMessage("Pick up all the blue Hexagonals");

				}
				else
				{
					picked_comb_no = combinations[11];
					pOut->PrintMessage("Pick up all the blue circles!");

				}


			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[12];
					pOut->PrintMessage("Pick up all the green rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[13];
					pOut->PrintMessage("Pick up all the green triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[28];
					pOut->PrintMessage("Pick up all the green Squares");

				}
				else if (dynamic_cast<CHexagonal*>(Fig))
				{
					picked_comb_no = combinations[14];
					pOut->PrintMessage("Pick up all the green Hexagonals");

				}
				else
				{
					picked_comb_no = combinations[15];
					pOut->PrintMessage("Pick up all the green circles!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[16];
					pOut->PrintMessage("Pick up all the red rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[17];
					pOut->PrintMessage("Pick up all the red triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[29];
					pOut->PrintMessage("Pick up all the red Squares");

				}
				else if (dynamic_cast<CHexagonal*>(Fig))
				{
					picked_comb_no = combinations[18];
					pOut->PrintMessage("Pick up all the red Hexagonals");

				}
				else
				{
					picked_comb_no = combinations[19];
					pOut->PrintMessage("Pick up all the red circles!");

				}

			}
		}
		else
		{
			if (dynamic_cast<CRectangle*>(Fig))
			{
				picked_comb_no = combinations[20];
				pOut->PrintMessage("Pick up all the unfilled rectangles!");

			}
			else if (dynamic_cast<CTriangle*>(Fig))
			{
				picked_comb_no = combinations[21];
				pOut->PrintMessage("Pick up all the unfilled triangles!");

			}
			else if (dynamic_cast<CHexagonal*>(Fig))
			{
				picked_comb_no = combinations[22];
				pOut->PrintMessage("Pick up all the unfilled Hexagonals");

			}
			else if (dynamic_cast<CCircle*>(Fig))
			{
				picked_comb_no = combinations[23];
				pOut->PrintMessage("Pick up all the unfilled circles!");

			}
			else if (dynamic_cast<CSquare*>(Fig))
			{
				picked_comb_no = combinations[24];
				pOut->PrintMessage("Pick up all the unfilled Squares");

			}

		}
		while (picked_comb_no > 0)
		{

			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{

					if (dynamic_cast<CSquare*>(Fig) && dynamic_cast<CSquare*>(clickedFig) && (clickedFig->GetGfxInfo().DrawClr == Fig->GetGfxInfo().DrawClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CRectangle*>(Fig) && dynamic_cast<CRectangle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CHexagonal*>(Fig) && dynamic_cast<CHexagonal*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CCircle*>(Fig) && dynamic_cast<CCircle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CTriangle*>(Fig) && dynamic_cast<CTriangle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}

					else
					{
						PrntScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pOut->PrintMessage("Toolbar clicked, game aborted.");
				picked_comb_no = -1;
			}
		}

		if (picked_comb_no == 0)
			PrntScore(3);

	}
	else pOut->PrintMessage("You must have at least two or more combinations to play pick by both!");
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}
