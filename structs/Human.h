// Imports
#include <chrono> // Library for dates in C++
#include <ctime>
#include <iomanip>
#include <random> // Libraru for random numbers
#include <vector>
#include <algorithm>

#include "LifeTree.h"

// Prototypes
Human * searchHumanByID(int id);
Human * searchHumanByName(string name, string lastName);
int generateRandomNumber(int to);
int generateUniqueID();
bool humanityCompleted();
void generateFriends(int humanID);
int countHumansSimilarInterest(Human * humanBase);
int humansCanBeFriends(Human * humanBase, Human * possibleFriend);
int calculateFriendshipScore(Human* humanBase, Human* possibleFriend);
void fillLifeTree(int array[], int from, int to);
int generateLifeTree();

// Structs
struct Human{
    int id;
    string state; // ALIVE, HELL or HEAVEN
    int generation;
    string name;
    string lastName;
    string country;
    string belief;
    string profession;
    time_t birthday;
    int sins[7];
    Human * friends[100];
    int socialMediaPriority[7];
    Angel * saviorAngel;

    Human(int _id, int _generation, string _state, string _name, string _lastName, string _country, string _belief, string _profession){
        id = _id;
        state = _state;
        generation = _generation;
        name = _name;
        lastName = _lastName;
        country = _country;
        belief = _belief;
        profession = _profession;
        auto currentTime = std::chrono::system_clock::now();
        birthday = std::chrono::system_clock::to_time_t(currentTime);
        for (int i = 0; i < 100; i++){
            sins[i] = 0;
            friends[i] = NULL;
        }
        for (int i = 0; i < 7; i++)
            socialMediaPriority[i] = generateRandomNumber(100);
        saviorAngel = NULL;
    }
    void print(){
        cout << "ID: " << id << endl;
        cout << "State: " << state << endl;
        cout << "Generation: " << generation << endl;
        cout << "Name: " << name << endl;
        cout << "lastName: " << lastName << endl;
        cout << "Country: " << country << endl;
        cout << "Belief: " << belief << endl;
        cout << "Profession: " << profession << endl;
        cout << "Birthday: ";
        std::tm* timeinfo = std::localtime(&birthday);
        if (timeinfo) {
            // Format the time using std::put_time
            cout << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S") << endl;
        } else {
            std::cerr << "Error converting time_t to tm structure." << std::endl;
        }
        cout << "Social Media: [";
        for (int i = 0; i < 7; i++)
        {
            cout << socialMediaPriority[i] << ", ";
        }
        cout << "]" << endl;
        cout << "Sins: [";
        for (int i = 0; i < 7; i++)
        {
            cout << sins[i] << ", ";
        }
        cout << "]" << endl; 
        cout << "Friends" << endl; 
        for (int i = 0; i < 100; i++){
            if (friends[i] != NULL){
                cout << friends[i]->id << endl;
                cout << "--------------------------------------" << endl;
            }     
        }
    }
    
    int addSins(){
        int sinsAmount = 0;
        for (int i = 0; i < 7; i++)
            sinsAmount += sins[i];
        return sinsAmount;
    }
};

// Functions
Human * generateHuman(){
    if(humanityCompleted())
        return NULL;
    int id = generateUniqueID();
    string name = names[generateRandomNumber(999)];
    string lastName = lastNames[generateRandomNumber(11)];
    string country = countries[generateRandomNumber(13)];
    string belief = beliefs[generateRandomNumber(4)];
    string profession = professions[generateRandomNumber(11)];
    return new Human(id, generation, "ALIVE", name, lastName, country, belief, profession);
}

void generateGeneration(int amount){
    generation++;
    int counter = 0;
    int humansGenerated[amount];
    while (!humanityCompleted() && counter < amount){
        Human * newHuman = generateHuman();
        humanity[newHuman->id] = newHuman;
        humansGenerated[counter++] = newHuman->id;
    }
    generateLifeTree();
    while (counter > 0)
         generateFriends(humansGenerated[--counter]);
}

int generateUniqueID(){
    bool validID = false;
    int id;
    while (!validID){
        id = generateRandomNumber(99999);
        if(humanity[id] == NULL)
            validID = true;
    }
    return id;
}

void generateFriends(int humanID) {
    Human* human = searchHumanByID(humanID);
    
    // Precompute a list of friend candidates
    vector<Human*> friendCandidates;

    for (int i = 0; i < humanitySize; i++) {
        if (humanity[i] != NULL && humanID != i) {
            if (humanity[i]->state == "ALIVE") {
                int friendScore = calculateFriendshipScore(human, humanity[i]);
                if (friendScore > 0) {
                    friendCandidates.push_back(humanity[i]);
                }
            }
        }
    }
    int numFriends = min(100, static_cast<int>(friendCandidates.size()));
    for (int i = 0; i < numFriends; i++) {
        human->friends[i] = friendCandidates[i];
    }
}

int calculateFriendshipScore(Human* humanBase, Human* possibleFriend) {
    int score = 0;

    if (humanBase->country != possibleFriend->country) 
        return score;
    if (humanBase->belief == possibleFriend->belief) 
        return ++score;
    if (humanBase->lastName == possibleFriend->lastName)
        return ++score;
    if (humanBase->profession == possibleFriend->profession)
        return ++score;

    return score;
}

Human * searchHumanByID(int id){
    // if (lifeTree->root != NULL){
    //     return search(id, lifeTree->root);
    // }
    for (int i = 0; i < humanitySize; i++)
        if(humanity[i] != NULL && i == id)
            return humanity[i];
    return NULL;
    
}

Human * searchHumanByName(string name, string lastName){
    for (int i = 0; i < humanitySize; i++)
        if(humanity[i] != NULL && humanity[i]->name == name && humanity[i]->lastName == lastName)
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

bool humanityCompleted(){ // Verify if the humanity array is full
    for (int i = 0; i < humanitySize; i++)
        if (humanity[i] == NULL)
            return false;
    return true;
}

int countHumansAlive(){
    int counter = 0;
    for (int i = 0; i < humanitySize; i++)
        if (humanity[i] != NULL && humanity[i]->state == "ALIVE")
            counter++;
    return counter;
}

Human * findHumanInPosition(int position){
    int counter = 0;
    for (int i = 0; i < humanitySize; i++){
        if (humanity[i] != NULL)
            counter++;
        if (counter == position)
            return humanity[i];
    }
        
    return NULL;
}

int calculateNodes(){
    int percentageHumans = countHumansAlive() * 0.01;
    int nodes;
    for (int i = 0; i < 17; i++)
        if(pow(2, i) > percentageHumans){
            nodes = pow(2, i);
            break;
        }
    return --nodes;
}

int generateLifeTree(){
    lifeTree = new Tree();
    int totalNodes = calculateNodes();
    int partitionLocations[totalNodes];
    int partition = countHumansAlive() / totalNodes;
    for (int i = 0; i < totalNodes; i++)
        partitionLocations[i] = partition * (i + 1);

    int min = (totalNodes / 2);
    int max = min;
    int counter = min;
    fillLifeTree(partitionLocations, 0, totalNodes);
    addPointerLeaf(lifeTree->root);
    return 0;
}

void fillLifeTree(int array[], int start, int end){
    if (start >= end) {
        return;
    }
    
    int size = abs(start - end);
    int middle = start + (size / 2);
    
    lifeTree->insert(findHumanInPosition(array[middle])->id);
    
    // Process the left half of the array
    fillLifeTree(array, start, middle);
    
    // Process the right half of the array
    fillLifeTree(array, middle + 1, end);
}