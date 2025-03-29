//#include <iostream>
#include "../include/monty_hall.h"

//using namespace std;

int main()
{
    monty_hall game;
    
    game.shuffleDoors();
    game.printShuffledDoors();

    return 0;
}