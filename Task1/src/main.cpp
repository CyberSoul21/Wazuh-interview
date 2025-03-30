#include "../include/monty_hall.h"
#include <thread>

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


int main(int argc, char* argv[])
{
    std::cout <<"Running simulation... "<<endl;

    const int total_simulations = 1000;
    monty_hall game_stay;
    monty_hall game_switch; 
    std::atomic<int> wins(0); // Atomic variable for thread-safe updates

    // Measure time for non-parallel program
    //auto start = std::chrono::high_resolution_clock::now();

    game_stay.stayStrategySimulation_chunk(total_simulations,std::ref(wins));
    std::cout <<"Games wons with stay strategy: "<<wins.load()<<endl;
    wins.store(0);

    //game_switch.switchStrategySimulation_chunk(total_simulations,std::ref(wins));
    //std::cout <<"Games wons with switch strategy: "<<wins.load()<<endl;
    //wins.store(0);

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> duration_stay = end - start;
    // Output the time taken for each strategy
    //std::cout << "Time taken running sequentially: " << duration_stay.count() << " seconds" << std::endl;


    //game_stay.reset();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    const int num_threads = std::thread::hardware_concurrency(); // Get number of hardware threads available
    const int simulations_per_thread = total_simulations / num_threads;

    std::vector<std::thread> threads;
    //std::atomic<int> wins(0); // Atomic variable for thread-safe updates
    
    // Measure time for non-parallel program
    //start = std::chrono::high_resolution_clock::now();

    // Create threads to run the simulation in parallel
    for (int i = 0; i < num_threads; i++)
    {
        threads.push_back(std::thread(std::mem_fn(&monty_hall::stayStrategySimulation_chunk), &game_stay, simulations_per_thread, std::ref(wins)));
    }

    // Wait for all threads to finish
    for (auto& t : threads)
    {
        t.join();
    }

    // Output the result
    std::cout << "Games won: " << wins.load() << std::endl;


    //end = std::chrono::high_resolution_clock::now();
    //duration_stay = end - start;
    // Output the time taken for each strategy
    //std::cout << "Time taken running in parallel: " << duration_stay.count() << " seconds" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    


    return 0;
}