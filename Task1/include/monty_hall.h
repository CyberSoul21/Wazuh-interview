#ifndef MONTY_HALL_H
#define MONTY_HALL_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
// import mutex from C++ standard library
#include <mutex>
#include <thread>
#include <atomic>
#include <list>

using namespace std;

class monty_hall
{
    private:

        std::vector<string> doors;
        int playerSelection;
        int doorOpened;
        // Mutex to protect the doors vector
        std::mutex doorsMutex;

    public:
    
    // Constructor
    monty_hall() {
        // Initialize member variables with default values
        doors = {"Car", "Goat", "Goat"};  // Initialize the doors
        playerSelection = 0;              // Set the initial player selection to 0
        doorOpened = 0;                   // Set the initial door opened to 0
    }

        // Destructor 
        ~monty_hall() {
            // If any dynamic memory or resources were allocated, release them here
            std::cout << "Destructor called, cleaning up resources" << std::endl;
        };

        //Reset
        inline void reset()
        {
            std::vector<string> doors = {"Car","Goat","Goat"};
            int playerSelection = 0;
            int doorOpened = 0;
        }

        void shuffleDoors();

        void setPlayerSelection();

        int getPlayerSelection();

        bool result();

        void printShuffledDoors() const;

        int generateRandomNumer();
        
        int selectRandomNumber(std::vector<int> listDoors);

        void hostOpenDoor();

        void playerSwitchDoor();

        void switchStrategySimulation_chunk(int num_simulations, std::atomic<int>& wins);

        void stayStrategySimulation_chunk(int num_simulations, std::atomic<int>& wins);
};

#endif