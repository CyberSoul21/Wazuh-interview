//#include <iostream>
#include "../include/monty_hall.h"
#include <thread>
//#include <atomic>

//using namespace std;



int main()
{
    /**
     * @brief 
     * TODO: 
     * 1- Finish game 1
     * 2- Let probability in one function
     * 3- Finish game 2
     * 4- Make file to run application
     * 5- Documentation of the all code
     * 6- Test cases
     * 
     */



    monty_hall game;
    
    
    int wins1=0;
    for(int i = 0; i < 100000; i++)
    {
        game.shuffleDoors();
        //game.printShuffledDoors();
        game.setPlayerSelection();
        if(game.result() == true)
        {
            wins1++;
        }
    }
    std::cout <<"Games wons: "<<wins1<<endl;
    

    /*
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const int total_simulations = 100000;
    const int num_threads = std::thread::hardware_concurrency(); // Get number of hardware threads available
    const int simulations_per_thread = total_simulations / num_threads;

    std::vector<std::thread> threads;
    std::atomic<int> wins(0); // Atomic variable for thread-safe updates
    
    // Create threads to run the simulation in parallel
    for (int i = 0; i < num_threads; i++)
    {
        threads.push_back(std::thread(std::mem_fn(&monty_hall::stayStrategySimulation_chunk), &game, simulations_per_thread, std::ref(wins)));
    }

    // Wait for all threads to finish
    for (auto& t : threads)
    {
        t.join();
    }

    // Output the result
    std::cout << "Games won: " << wins.load() << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    */


    return 0;
}