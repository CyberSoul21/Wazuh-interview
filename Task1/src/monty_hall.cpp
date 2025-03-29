#include "../include/monty_hall.h"

void monty_hall::shuffleDoors()
{
    /*
    // Use Mersenne Twister and random_device to shuffle
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(doors.begin(), doors.end(), gen);  // Shuffle the vector
    */


    // Create a random device to seed the Mersenne Twister
    std::random_device rd;

    // Initialize the Mersenne Twister engine
    std::mt19937 gen(rd());

    // Define the distribution (e.g., uniform distribution between 1 and 3)
    std::uniform_int_distribution<> dis(1, 3);

    // Generate and print a random number
    int randomNumber = dis(gen);
    std::cout << "Random number: " << randomNumber << std::endl;

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
    // Create a random device to seed the Mersenne Twister
    std::random_device rd;

    // Initialize the Mersenne Twister engine
    std::mt19937 gen(rd());

    // Define the distribution (e.g., uniform distribution between 1 and 3)
    std::uniform_int_distribution<> dis(1, 3);

    playerSelection = dis(gen) - 1;
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