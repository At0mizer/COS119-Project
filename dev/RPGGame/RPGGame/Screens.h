#pragma once
#include "Helper.h"
#include <iomanip>
#include <string>

namespace Screens
{
    static void DisplayWelcomeMessage()
    {
        Helper::Print("\t\t\t\t\t##==================================##", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t||   #--------------------------#   ||", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t||   |    THE FALLEN KINGDOM    |   ||", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t||   #--------------------------#   ||", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t|| <::::::::::[]=o  o=[]::::::::::> ||", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t||       ~ A Text Based RPG ~       ||", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t##==================================##", Helper::Color::Red, 1);

        Helper::PrintBlankLines(1);

    }

    static void DisplayCredits()
    {
        Helper::ClearConsole();

        Helper::Print(("\t\t\t\t\t======--------------------------======"), Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t|==|            CREDITS           |==|", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t======--------------------------======", Helper::Color::Red, 1);

        Helper::Print("\t\t\t\t\t\t   Bradley Musinski", Helper::Color::Red, 2);

        Helper::Continue();
        Helper::ClearConsole();
    }

    static void GoodbyeMessage()
    {
        Helper::Print("\t\t\t\t\t======--------------------------======", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t|==|            GoodBye :)        |==|", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t======--------------------------======", Helper::Color::Red, 1);
    }

    static void MenuOptions()
    {
        Helper::Print("\t\t\t\t\t\t - 1. New Adventure -", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t\t   - 2. Load Game -", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t\t    - 3. Credits -", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t\t   - 4. Quit Game -", Helper::Color::Red, 1);
    }
}