// Imports
#include <iostream>
#include <chrono> // Library for dates in C++
#include <iostream>
#include <fstream>
using namespace std;

// Structs
struct Human;

// Variables
const int humanitySize = 100000;
Human * humanity[humanitySize];
string names[1000];
string lastNames[12];
string countries[14];
string beliefs[5];
string professions[12];
string socialMedia[7];
string deadlySins[] = {
    "lust",
    "gluttony",
    "avarice",
    "laziness",
    "anger",
    "envy",
    "arrogance"
};

bool loadData(string array[], string source){
    std::ifstream file(source);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return false;
    }
    string line;
    int counter = 0;
    while(getline(file, line)){
        array[counter++] = line;
    }
    file.close();
    return true;
}

void initializeData(){
    loadData(names, "Data/Names.txt");
    loadData(lastNames, "Data/LastNames.txt");
    loadData(professions, "Data/Professions.txt");
    loadData(beliefs, "Data/Beliefs.txt");
    loadData(countries, "Data/Countries.txt");
    for (int i = 0; i < 100000; i++)
        humanity[i] = NULL; 
}