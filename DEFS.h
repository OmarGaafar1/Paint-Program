#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"
//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	Draw_Circle,
	Draw_Triangle,
	Draw_Square,
	Draw_Hex,
	Redo,
	Move,
	Undo,
	Delete,
	Clear,
	Start_rec,
	End_rec,
	Play_Rec,
	Save,
	Load,
	Pick_By_Type,
	Pick_By_color,
	Pick_By_Both,
	Change_filling_color,
	Change_Drawing_color,
	Selection,      // A Click on selection icon
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	SOUND,
	STATUS
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};
struct REDO
{
	int type;
	//CFigure *Fig;
	color Cl;

};
enum shape {
	rect,
	circ,
	square,
	triangle,
	Hexagonal,
};

#endif