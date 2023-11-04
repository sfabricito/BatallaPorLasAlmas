// Imports
#include "Log.h"

// Prototypes
struct Demon;
int searchDemonIndex(string name);
void addHumansToFamilies(Demon * demon, Human * humans[], int size);
void insertInOrderHumans(Demon * demon, Human * arr[], Human * human, int capacity);
void insertInDescendingOrderHumans(Demon* demon, Human* humans[], int length, Human* human);
int searchIndexHigherSinByHuman(int id);
Demon * searchDemonByName(string demonName);
string generateMessage(int sins, string sin, string demon);

// Structs
struct Family{
    int totalSins;
    string country;
    string lastName;
    Human * humans[humanitySize];

    Family(string _country, string _lastName){
        country = _country;
        lastName = _lastName;
        totalSins = 0;
        for (int i = 0; i < humanitySize; i++)
            humans[i] = NULL;
    }

    Human * addHuman(Human * human, int sinsCommited){
        for (int i = 0; i < humanitySize; i++)
        {
            if (humans[i] == NULL)
            {
                humans[i] = human;
                totalSins += sinsCommited;
                break;
            }
        }
        return NULL;
    }
    void print(){
        for (int i = 0; i < humanitySize; i++)
        {
            if (humans[i] == NULL)
                break;
            humans[i]->print();
        }
        
    }
};
struct Demon{
    string type;
    int totalFamilies;
    Family * families[lastNamesSize * countriesSize];

    Demon(string _type){
        type = _type;
        totalFamilies = 0;
        for (int i = 0; i < (lastNamesSize * countriesSize); i++)
            families[i] = NULL;
    }
    void calculateMaximum(){}
    void printFamilies(){
        for (int i = 0; i < (lastNamesSize * countriesSize); i++)
        {
            if (families[i] != NULL)
            {
                cout << "Family: " << i << endl;
                cout << "Country: " << families[i]->country << endl;
                cout << "Last Name: " << families[i]->lastName << endl;
                cout << "Total Sins: " << families[i]->totalSins << endl;
                cout << "Humans: " << endl;
                cout << "-----------------------" << endl;
                families[i]->print();
                

            }
        }
    }

    void addHumansToFamilies( Human * humans[], int size){ // size = total humans
        int stop = (lastNamesSize * countriesSize); // Possibles families
        for (int i = 0; i < size; i++)
        {
            for (int y = 0; y < stop; y++)
            {
                if (families[y] == NULL){
                    families[y] = new Family(humans[i]->country, humans[i]->lastName);
                    totalFamilies++;
                    families[y]->addHuman(humans[i], humans[i]->sins[searchDemonIndex(type)]);
                    break;
                }
                else if((families[y]->country == humans[i]->country) && (families[y]->lastName == humans[i]->lastName)){
                    families[y]->addHuman(humans[i], humans[i]->sins[searchDemonIndex(type)]);
                    break;
                }
            }
        }
    }
    void maxHeapify(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int max = index;

        // Check if left child exists and is greater than the current max
        if (left < totalFamilies && families[left]->totalSins > families[max]->totalSins) {
            max = left;
        }

        // Check if right child exists and is greater than the current max
        if (right < totalFamilies && families[right]->totalSins > families[max]->totalSins) {
            max = right;
        }

        // If the maximum value is not at the current index, swap and recursively call maxHeapify
        if (max != index) {
            Family * temp = families[max];
            families[max] = families[index];
            families[index] = temp;

            // Recursively call for the subtree
            maxHeapify(max); // Update the index to max
        }
    }
};

void condemnHumans(string demonName){
    Demon * demon = searchDemonByName(demonName);
    Human * humans[humanitySize];
    int counter = 0;
    int demonID = searchDemonIndex(demon->type);
    for (int i = 0; i < humanitySize; i++){
        if (humanity[i] != NULL && searchIndexHigherSinByHuman(i) == demonID){
            Human * human = searchHumanByID(i);
            human->state == "HELL";
            hellRecord->insertLog(human, generateMessage(human->sins[searchIndexHigherSinByHuman(i)], deadlySins[searchDemonIndex(demonName)] ,demonName));
            insertInDescendingOrderHumans(demon, humans, counter++, human);
        }  
    }
    demon->addHumansToFamilies(humans, counter * 0.05);
    demon->maxHeapify(0);
}

int searchDemonIndex(string name){
    for (int i = 0; i < 7; i++)
        if (demonsTemplate[i] == name)
            return i;
    return -1;
}

int searchIndexHigherSinByHuman(int id){
    int index = 0;
    Human * human = searchHumanByID(id);
    if (human != NULL)
        for (int i = 0; i < 7; i++){
            if (human->sins[i] > human->sins[index]){
                index = i;
            }
        }      
    return index;
}

void insertInDescendingOrderHumans(Demon* demon, Human* humans[], int length, Human* human) {
    int i = length - 1; // Start from the end of the array
    int humanSins = human->sins[searchDemonIndex(demon->type)];
    
    while (i >= 0 && humanSins > humans[i]->sins[searchDemonIndex(demon->type)]) {
        humans[i + 1] = humans[i]; // Shift elements to the right
        i--;
    }
    
    // Insert the new value at the correct position
    humans[i + 1] = human;
    length++; // Increment the length of the array
}

void createDemons(){
    for (int i = 0; i < 7; i++)
        demons[i] = new Demon(demonsTemplate[i]);
}

Demon * searchDemonByName(string demonName){
    for (int i = 0; i < 7; i++)
        if (demons[i]->type == demonName)
            return demons[i];
    return NULL;
}

string generateMessage(int sins, string sin, string demon){
    string message = "dead on ";
    auto currentTime = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* timeinfo = std::localtime(&time);
    if (timeinfo) {
        std::stringstream ss;
        ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
        message += ss.str();
    }
    message += "sentenced by " + sins;
    message += " sins of " + sin;
    message += " by " + demon;
    message += " demon.";
    return message;
}