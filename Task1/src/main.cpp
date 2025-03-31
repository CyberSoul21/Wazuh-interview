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

    int total_simulations = 0;
    bool stay = false;
    bool change = false;
    bool both = false;
    monty_hall game_stay;
    monty_hall game_switch; 
    std::atomic<int> wins(0); // Atomic variable for thread-safe updates
    std::vector<std::thread> threads;


    const int num_threads = std::thread::hardware_concurrency(); // Get number of hardware threads available

    // Measure time for non-parallel program
    //auto start = std::chrono::high_resolution_clock::now();
    
    //Default simulation without arguments
    if(argc == 1)
    {
        total_simulations = 100000;        
    }
    else if(argc == 3)
    {
        // First argument (string)
        std::string strategy = argv[1];  
        
        //Converte second argument to an integer
        try 
        {
            total_simulations = std::stoi(argv[2]);  // Convert the second argument to an integer
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << "Invalid argument: the second argument must be an integer." << std::endl;
            return 1;
        } 
        catch (const std::out_of_range& e) 
        {
            std::cout << "Out of range: the integer is too large." << std::endl;
            return 1;
        }

        if(strategy == "stay")
        {
            stay = true;
        }
        else if(strategy == "switch")
        {
            change = true;
        }
        else if(strategy == "both")
        {
            both = true;
        }
        else
        {
            std::cout << "Invalid argument: the first argument must be an option: stay, switch or both." << std::endl;
            return 1; 
        } 

    }
    else
    {
        std::cout << "Too many arguments! Expected only two arguments (a string and an integer)." << std::endl;
        return 1;  // Exit the program with an error code 
    }

    const int simulations_per_thread = total_simulations / num_threads;


    if(total_simulations < 1000000)
    {
        if(stay)
        {
            game_stay.stayStrategySimulation_chunk(total_simulations,std::ref(wins));
            std::cout <<"Games won with stay strategy: "<<wins.load()<<endl;
            wins.store(0);
        }
        else if(change)
        {
            game_switch.switchStrategySimulation_chunk(total_simulations,std::ref(wins));
            std::cout <<"Games won with switch strategy: "<<wins.load()<<endl;
            wins.store(0);
        }
        else if(both || argc == 1)
        {
            game_stay.stayStrategySimulation_chunk(total_simulations,std::ref(wins));
            std::cout <<"Games won with stay strategy: "<<wins.load()<<endl;
            wins.store(0);

            game_switch.switchStrategySimulation_chunk(total_simulations,std::ref(wins));
            std::cout <<"Games won with switch strategy: "<<wins.load()<<endl;
            wins.store(0);
        }

    }
    else if(total_simulations >= 1000000 && total_simulations <= 10000000)
    {
        if(stay)
        {
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
            std::cout << "Games won with stay strategy: " << wins.load() << std::endl;
            wins.store(0);
        }
        else if(change)
        {
            // Create threads to run the simulation in parallel
            for (int i = 0; i < num_threads; i++)
            {
                threads.push_back(std::thread(std::mem_fn(&monty_hall::switchStrategySimulation_chunk), &game_switch, simulations_per_thread, std::ref(wins)));
            }

            // Wait for all threads to finish
            for (auto& t : threads)
            {
                t.join();
            }
            // Output the result
            std::cout << "Games won with switch strategy: " << wins.load() << std::endl;
            wins.store(0); 
        }
        else if(both || argc == 1)
        {
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
            std::cout << "Games won with stay strategy: " << wins.load() << std::endl;
            wins.store(0);
            threads.clear();
            // Create threads to run the simulation in parallel
            for (int i = 0; i < num_threads; i++)
            {
                threads.push_back(std::thread(std::mem_fn(&monty_hall::switchStrategySimulation_chunk), &game_switch, simulations_per_thread, std::ref(wins)));
            }

            // Wait for all threads to finish
            for (auto& t : threads)
            {
                t.join();
            }
            // Output the result
            std::cout << "Games won with switch strategy: " << wins.load() << std::endl; 
            wins.store(0);
        }

    }
    else if(total_simulations > 10000000)
    {
        std::cout << "Warning: You requested too many simulations..." << std::endl;
        return 1;  // Exit the program with an error code
    }

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> duration_stay = end - start;
    // Output the time taken for each strategy
    //std::cout << "Time taken running sequentially: " << duration_stay.count() << " seconds" << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}