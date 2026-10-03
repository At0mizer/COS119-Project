#pragma once
#include "Helper.h"

namespace Screens
{
    static void DisplayWelcomeMessage()
    {
        Helper::Print("\t\t\t\t\t======--------------------------======", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t|==|      THE FALLEN KINGDOM      |==|", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t|==|                              |==|", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t|==|       A Text Based RPG       |==|", Helper::Color::Red, 1);
        Helper::Print("\t\t\t\t\t======--------------------------======", Helper::Color::Red, 1);

        Helper::PrintBlankLines(1);
    }

    static void DisplayCredits()
    {
        Helper::ClearConsole();

        Helper::Print("\t\t\t\t\t======--------------------------======", Helper::Color::Red, 1);
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
}