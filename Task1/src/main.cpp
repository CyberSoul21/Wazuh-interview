//#include <iostream>
#include "../include/monty_hall.h"
#include <thread>
#include <atomic>

//using namespace std;

//int wins = 0;

// Function to run a chunk of simulations
void run_simulation_chunk(int num_simulations, monty_hall& game, std::atomic<int>& wins)
{
    int local_wins = 0;
    for (int i = 0; i < num_simulations; i++)
    {
        game.shuffleDoors();
        game.setPlayerSelection();
        if (game.result() == true)
        {
            local_wins++;
        }
    }
    wins += local_wins;  // Atomically update the shared counter
}

int main()
{
    
    monty_hall game;
    
    /*
    int wins1=0;
    for(int i = 0; i < 10000000; i++)
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
    */


    const int total_simulations = 10000000;
    const int num_threads = std::thread::hardware_concurrency(); // Get number of hardware threads available
    const int simulations_per_thread = total_simulations / num_threads;

    std::vector<std::thread> threads;
    std::atomic<int> wins(0); // Atomic variable for thread-safe updates

    //monty_hall game;

    // Create threads to run the simulation in parallel
    for (int i = 0; i < num_threads; i++)
    {
        threads.push_back(std::thread(run_simulation_chunk, simulations_per_thread, std::ref(game), std::ref(wins)));
    }

    // Wait for all threads to finish
    for (auto& t : threads)
    {
        t.join();
    }

    // Output the result
    std::cout << "Games won: " << wins.load() << std::endl;
    return 0;
    
    return 0;
}