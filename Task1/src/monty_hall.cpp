#include "../include/monty_hall.h"

void monty_hall::shuffleDoors()
{
    // Lock the mutex to ensure thread-safe access to doors
    std::lock_guard<std::mutex> lock(doorsMutex);
    int randomNumber = generateRandomNumer();

    for(int i=0; i<doors.size(); i++)
    {
        if(i == (randomNumber - 1))
        {
            doors[i] = "Car";
        }
        else
        {
            doors[i] = "Goat";
        }
    }
}

void monty_hall::printShuffledDoors() const
{
    int counter = 1;
    // Print shuffled vector
    for (string door : doors) {
        std::cout <<"Door "<<counter<<": " << door <<endl;
        counter++;
    }
    std::cout << std::endl;
}

void monty_hall::setPlayerSelection()
{
    playerSelection = generateRandomNumer() - 1;
}

int monty_hall::getPlayerSelection()
{
    return playerSelection;
}

bool monty_hall::result()
{
    if(doors[playerSelection] == "Car")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int monty_hall::generateRandomNumer()
{
    // Create a random device to seed the Mersenne Twister
    std::random_device rd;

    // Initialize the Mersenne Twister engine
    std::mt19937 gen(rd());

    // Define the distribution (e.g., uniform distribution between 1 and 3)
    std::uniform_int_distribution<> dis(1, 3);

    // Generate and print a random number
    int randomNumber = dis(gen);
    //std::cout << "Random number: " << randomNumber << std::endl;

    return randomNumber;
}

// Function to run a chunk of simulations
void monty_hall::run_simulation_chunk(int num_simulations, std::atomic<int>& wins)
{
    int local_wins = 0;
    for (int i = 0; i < num_simulations; i++)
    {
        shuffleDoors();
        setPlayerSelection();
        if (result() == true)
        {
            local_wins++;
        }
    }
    wins += local_wins;  // Atomically update the shared counter
}