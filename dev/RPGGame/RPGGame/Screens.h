#pragma once
#include <iomanip>
#include <string>
#include "GameEngine.h"

namespace Screens
{
    inline void DisplayWelcomeMessage()
    {
        GEngine->Print("\t\t\t\t\t##==================================##", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t||   #--------------------------#   ||", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t||   |    THE FALLEN KINGDOM    |   ||", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t||   #--------------------------#   ||", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t|| <::::::::::[]=o  o=[]::::::::::> ||", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t||       ~ A Text Based RPG ~       ||", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t##==================================##", Color::Red, 1);

        GEngine->PrintBlankLines(1);

    }

    inline void DisplayCredits()
    {
        GEngine->ClearConsole();

        GEngine->Print(("\t\t\t\t\t======--------------------------======"), Color::Red, 1);
        GEngine->Print("\t\t\t\t\t|==|            CREDITS           |==|", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t======--------------------------======", Color::Red, 1);

        GEngine->Print("\t\t\t\t\t\t   Bradley Musinski", Color::Red, 2);

        GEngine->Continue();
        GEngine->ClearConsole();
    }

    inline void GoodbyeMessage()
    {
        GEngine->Print("\t\t\t\t\t======--------------------------======", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t|==|            GoodBye :)        |==|", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t======--------------------------======", Color::Red, 1);
    }

    inline void MenuOptions()
    {
        GEngine->Print("\t\t\t\t\t\t - 1. New Adventure -", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t\t   - 2. Load Game -", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t\t    - 3. Credits -", Color::Red, 1);
        GEngine->Print("\t\t\t\t\t\t   - 4. Quit Game -", Color::Red, 1);
    }
}