#include "GameManager.h"
#include "Dialogue.h"

void GameManager::Run()
{
	Intro();
}

void GameManager::Intro()
{
	Dialogue::StartDialogue();
}
