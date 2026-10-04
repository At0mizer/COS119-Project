#pragma once
#include <iostream>
#include <string>
#include "Helper.h"
#include "Screens.h"

/*
* Namespace menus is a UI Helper layer. 
* It keeps the code separate from the engine logic
* 
*/

namespace Menus
{

    // Main Menu 
    static int MainMenu()
    {

        bool bIsLooping = true;

        while (bIsLooping)
        {
            Screens::DisplayWelcomeMessage();

            Helper::Print("\t\t\t\t\t\t   - 1. New Game -", Helper::Color::Red, 1);
            Helper::Print("\t\t\t\t\t\t   - 2. Load Game -", Helper::Color::Red, 1);
            Helper::Print("\t\t\t\t\t\t    - 3. Credits -", Helper::Color::Red, 1);
            Helper::Print("\t\t\t\t\t\t     - 4. Quit -", Helper::Color::Red, 1);
            Helper::Print("\t\t\t\t\t\t\t>> ", Helper::Color::Red, 0);

            std::string userChoice;
            getline(std::cin, userChoice);

            int convChoice = std::stoi(userChoice);
            
            switch (convChoice)
            {
            case 1:
                Helper::ClearConsole();
                break;
                
            case 2:
                Helper::ClearConsole();
                break;

            case 3:
                Helper::ClearConsole();
                Screens::DisplayCredits();
                break;
            case 4:
                Helper::ClearConsole();
                Screens::GoodbyeMessage();
                bIsLooping = false;
                
                break;

            default:
                Helper::Print("ERROR: Invalid Choice...", Helper::Color::Red, 1);
                Helper::Continue();
                Helper::ClearConsole();
                break;
            }


            return convChoice;
        }
    }
}