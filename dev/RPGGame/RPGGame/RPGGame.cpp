
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

//bool MainMenu();

int main()
{

    /*
    * MainMenu
    *
    * Will be a switch
    * First case of the switch will be the new game / play option
    *       - Upon selecting the play option, it will call a function in the GameMode class that starts the gameplay.
    *       - This will 
    * Second case will be the load function, 
    *       - It will show the save file of the player shown by the character's name (File will be .bin) 
    * Third case will exit the program
    *       - Just exits the program while saving the player data
    */
    std::cout << "Hello World!\n";
    
    //while (MainMenu());

    std::cout << "Starting Timer..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "5 seconds have passed!" << std::endl;
    return 0;

}

//Development Process
// Plan -> Build -> Track -> Test -> Improve

// 3+ classes
//.h and .cpp separateion
// vectors
// pointers
// User interaction
// Input
// Persistent
// Structured, interacting systems

// No Graphical detours
//  no GUI frameworks
//  Qt
//  raylib
//  SDL
//  SFML

// Start small, build the core, test constantly, backlog the chaos, expand with purpose

// GitHub =/ Google Drive

// BACKLOG : Eventually
// TODO : Coming up next
// IN PROGRESS : Actively working
// COMPLETED + tested

// PULL REQUEST at the end of the week
// When should you make the PR
//  Don't do after you create it!! Make sure it is completed and it works!

// Merge -> Close -> Verify

// Plan -> Update -> Work in dev -> Commit -> Test -> Merge -> Close the PR
// 
// 
// Plan
// Track
// Build
// Test
// Commit 
// Merge 
// Push

//bool MainMenu()
//{
//    //bool bIsLooping;
//
//    std::string userChoice;
//    int convChoice = std::stoi(userChoice);
//
//    //switch (convChoice)
//    //{
//    //case 1:
//
//    //}
//
//    //return bIsLooping;
//}
