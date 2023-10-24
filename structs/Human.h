// Imports
#include <chrono> // Library for dates in C++
#include <random> // Libraru for random numbers
#include "Data.h"
// Prototypes
struct Human;
Human * searchHumanByID(Human * humanity[], int id);
int generateRandomNumber(int to);
int generateUniqueID(Human * humanity[]);
bool humanityCompleted(Human * humanity[]);

// Structs
struct Human{
    int id;
    string state; // ALIVE, HELL or HEAVEN
    string name;
    string lastName;
    string country;
    string belief;
    string profession;
    time_t birthday;
    string sins[100];
    Human * friends[100];
    int socialMediaPriority[7];

    Human(int _id, string _state, string _name, string _lastName, string _country, string _belief, string _profession){
        id = _id;
        state = _state;
        name = _name;
        lastName = _lastName;
        country = _country;
        belief = _belief;
        profession = _profession;
        auto currentTime = std::chrono::system_clock::now();
        birthday = std::chrono::system_clock::to_time_t(currentTime);
        for (int i = 0; i < 100; i++){
            sins[i] = "";
            friends[i] = NULL;
        }
        for (int i = 0; i < 7; i++)
            socialMediaPriority[i] = generateRandomNumber(100);
        
        
    }
};

// Functions
Human * createHuman(Human * humanity[]){
    if(humanityCompleted(humanity))
        return NULL;
    int id = generateUniqueID(humanity);
    string name = names[generateRandomNumber(999)];
    string lastName = lastNames[generateRandomNumber(11)];
    string country = countries[generateRandomNumber(13)];
    string belief = beliefs[generateRandomNumber(4)];
    string profession = professions[generateRandomNumber(11)];
    return new Human(id, "ALIVE", name, lastName, country, belief, profession);
}

void createHumans(Human * humanity[], int amount){
    int counter = 0;
    while (!humanityCompleted(humanity) && counter < amount){
        Human * newHuman = createHuman(humanity);
        humanity[newHuman->id] = newHuman;
        counter++;
    }
}

int generateUniqueID(Human * humanity[]){
    bool validID = false;
    int id;
    while (!validID){
        id = generateRandomNumber(99999);
        if(searchHumanByID(humanity, id) == NULL)
            validID = true;
    }
    return id;
}

Human * searchHumanByID(Human * humanity[], int id){
    for (int i = 0; i < 100000; i++)
        if(humanity[i] != NULL && i == id)
            return humanity[i];
    return NULL;
}

int generateRandomNumber(int to){
    random_device rd;  // A random device to seed the generator
    mt19937 gen(rd()); // Mersenne Twister 19937 engine

    uniform_int_distribution<int> distribution(0, to);

    // Generate a random number using the generator and distribution
    return distribution(gen);
}

bool humanityCompleted(Human * humanity[]){
    for (int i = 0; i < 100000; i++)
        if (humanity[i] == NULL)
            return false;
    return true;
}