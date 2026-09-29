#pragma once
#include "Helper.h"

namespace Screens
{
    static void DisplayWelcomeMessage()
    {
        Helper::Print("\t\t\t\t\t======--------------------------======", 1);
        Helper::Print("\t\t\t\t\t|==|      THE FALLEN KINGDOM      |==|", 1);
        Helper::Print("\t\t\t\t\t|==|                              |==|", 1);
        Helper::Print("\t\t\t\t\t|==|       A Text Based RPG       |==|", 1);
        Helper::Print("\t\t\t\t\t======--------------------------======", 1);

        Helper::PrintBlankLines(1);
    }

    static void DisplayCredits()
    {
        Helper::ClearConsole();

        Helper::Print("\t\t\t\t\t======--------------------------======", 1);
        Helper::Print("\t\t\t\t\t|==|            CREDITS           |==|", 1);
        Helper::Print("\t\t\t\t\t======--------------------------======", 1);

        Helper::Print("\t\t\t\t\t\t   Bradley Musinski", 2);

        Helper::Continue();
        Helper::ClearConsole();
    }
}