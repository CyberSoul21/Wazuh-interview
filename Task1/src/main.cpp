//#include <iostream>
#include "../include/monty_hall.h"

//using namespace std;

int main()
{
    monty_hall game;
    
    //game.shuffleDoors();
    //game.printShuffledDoors();
    //game.setPlayerSelection();

    int wins = 0;
    for(int i = 0; i < 1000000; i++)
    {
        game.shuffleDoors();
        //game.printShuffledDoors();
        game.setPlayerSelection();
        if(game.result() == true)
        {
            wins++;
        }
    }
    std::cout <<"Games wons: "<<wins<<endl;
    return 0;
}