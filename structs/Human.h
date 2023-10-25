// Imports
#include <chrono> // Library for dates in C++
#include <ctime>
#include <iomanip>
#include <random> // Libraru for random numbers
#include <vector>
#include <algorithm>
#include "Data.h"
// Prototypes
Human * searchHumanByID(int id);
int generateRandomNumber(int to);
int generateUniqueID();
bool humanityCompleted();
void generateFriends(int humanID);
int countHumansSimilarInterest(Human * humanBase);
int humansCanBeFriends(Human * humanBase, Human * possibleFriend);
int calculateFriendshipScore(Human* humanBase, Human* possibleFriend);

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
    int sins[7];
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
            sins[i] = 0;
            friends[i] = NULL;
        }
        for (int i = 0; i < 7; i++)
            socialMediaPriority[i] = generateRandomNumber(100);
    }
    void print(){
        cout << "ID: " << id << endl;
        cout << "State: " << state << endl;
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
        cout << "Friends" << endl; 
        for (int i = 0; i < 100; i++){
            if (friends[i] != NULL){
                cout << friends[i]->id << endl;
                cout << "--------------------------------------" << endl;
            }     
        }
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
    return new Human(id, "ALIVE", name, lastName, country, belief, profession);
}

void generateHumans(int amount){
    int counter = 0;
    int humansGenerated[amount];
    while (!humanityCompleted() && counter < amount){
        Human * newHuman = generateHuman();
        humanity[newHuman->id] = newHuman;
        humansGenerated[counter++] = newHuman->id;
    }
    while (counter > 0)
        generateFriends(humansGenerated[--counter]);
}

int generateUniqueID(){
    bool validID = false;
    int id;
    while (!validID){
        id = generateRandomNumber(99999);
        if(searchHumanByID(id) == NULL)
            validID = true;
    }
    return id;
}

void generateFriends(int humanID) {
    Human* human = searchHumanByID(humanID);
    int maxFriends = 100;  // Max number of friends

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

    // Shuffle the candidates to randomize friend selection
    shuffle(friendCandidates.begin(), friendCandidates.end(), std::default_random_engine(std::random_device{}()));

    // Select friends from the candidate list
    int numFriends = min(maxFriends, static_cast<int>(friendCandidates.size()));

    for (int i = 0; i < numFriends; i++) {
        human->friends[i] = friendCandidates[i];
    }
}

int calculateFriendshipScore(Human* humanBase, Human* possibleFriend) {
    int score = 0;

    if (humanBase->country != possibleFriend->country) {
        return score;
    }

    if (humanBase->belief == possibleFriend->belief) {
        score++;
    }

    if (humanBase->lastName == possibleFriend->lastName) {
        score++;
    }

    if (humanBase->profession == possibleFriend->profession) {
        score++;
    }

    return score;
}

Human * searchHumanByID(int id){
    for (int i = 0; i < humanitySize; i++)
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

int humansCanBeFriends(Human * humanBase, Human * possibleFriend){
    if (
        (humanBase->country == possibleFriend->country) && 
        (
            humanBase->belief == possibleFriend->belief || 
            humanBase->lastName == possibleFriend->lastName || 
            humanBase->profession == possibleFriend->profession
        )
    )
        return true;
    return false;
}

bool humanityCompleted(){ // Verify if the humanity array is full
    for (int i = 0; i < humanitySize; i++)
        if (humanity[i] == NULL)
            return false;
    return true;
}