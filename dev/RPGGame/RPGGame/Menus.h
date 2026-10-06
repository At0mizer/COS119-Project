#pragma once
#include <iostream>
#include <string>
#include "Helper.h"
#include "Screens.h"
#include "Input.h"

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
            Screens::MenuOptions();

            int MenuChoice = Input::GetInput("\t\t\t\t\t\t\t >> ", 1, 4);
   
            switch (MenuChoice)
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


            return MenuChoice;
        }
    }
}