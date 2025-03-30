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
    
        //Constructor
        monty_hall()
        {
            std::vector<string> doors = {"","",""};
            int playerSelection = 0;
            int doorOpened = 0;
        }

        // Destructor 
        ~monty_hall() {
            // If any dynamic memory or resources were allocated, release them here
            std::cout << "Destructor called, cleaning up resources" << std::endl;
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