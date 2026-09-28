
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    std::cout << "Hello World!\n";

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