#include "Sound.h" 

Sound::Sound(ApplicationManager *pApp, bool *ON_OFF) :Action(pApp), ON_OR_OFF(ON_OFF)
{}

void Sound::ReadActionParameters()
{}

void Sound::Execute()
{
	Output *pOut = pManager->GetOutput();
	if (*ON_OR_OFF == 0)
	{
		*ON_OR_OFF = 1;
		UI.Sound = 1;
		pOut->PrintMessage("Sounds ON");
	}
	else
	{
		UI.Sound = 0;
		*ON_OR_OFF = 0;
		pOut->PrintMessage("Sounds OFF");
	}
}


