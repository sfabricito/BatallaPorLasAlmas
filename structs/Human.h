// Imports
#include <chrono> // Library for dates in C++
#include "../Data.h"
// Prototypes
struct Human;

// Structs
struct Human{
    int id;
    string name;
    string lastName;
    string country;
    string belief;
    string profession;
    time_t birthday;
    string sins[100];
    Human * friends[100];
    int socialMediaPriority[7];
};

// Functions