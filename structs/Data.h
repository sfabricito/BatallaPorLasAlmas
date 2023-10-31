// Imports
#include <iostream>
#include <chrono> // Library for dates in C++
#include <iostream>
#include <fstream>
using namespace std;

// Structs
struct Human;
struct Tree;

// Variables
const int humanitySize = 100000;
const int lastNamesSize = 12;
const int countriesSize = 14;
int generation = 0;

Human * humanity[humanitySize];
Tree * lifeTree;

// Arrays
string names[1000];
string lastNames[lastNamesSize];
string countries[countriesSize];
string beliefs[5];
string professions[12];
const string socialMedia[] = {
    "TWITTER", // anger
    "INSTAGRAM",
    "NETFLIX", // laziness
    "TINDER", // lust
    "FACEBOOK",
    "LINKEDIN", // avarice
    "PINTEREST"
};
const string deadlySins[] = {
    "LUST", // lujuria
    "GLUTTONY", // glotonería
    "AVARICE", // avaricia
    "LAZINESS", // pereza
    "ANGER", // enojo
    "ENVY", // emvidia
    "ARROGANCE" // arrogancia
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