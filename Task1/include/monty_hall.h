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

using namespace std;

class monty_hall
{
    private:
        //int m_year{};
        std::vector<string> doors = {"Car","Goat","Goat"};
        int playerSelection = 0;
        // Mutex to protect the doors vector
        std::mutex doorsMutex;

    public:
        //monty_hall();

        void shuffleDoors();

        void setPlayerSelection();

        int getPlayerSelection();

        bool result();

        void printShuffledDoors() const;

        void run_simulation_chunk(int num_simulations, std::atomic<int>& wins);

};

#endif