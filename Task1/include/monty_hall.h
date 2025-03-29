#ifndef MONTY_HALL_H
#define MONTY_HALL_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


using namespace std;

class monty_hall
{
    private:
        //int m_year{};
        std::vector<string> doors = {"Car","Goat","Goat"};
        int playerSelection = 0;

    public:
        //monty_hall();

        void shuffleDoors();

        void printShuffledDoors() const;

};

#endif