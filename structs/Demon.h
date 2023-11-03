// Imports
#include "Post.h"

// Prototypes
struct Demon;
void addHumansToFamilies(Demon * demon, Human * humans[], int size);
void insertInOrderHumans(Demon * demon, Human * arr[], Human * human, int capacity);
void insertInDescendingOrderHumans(Demon* demon, Human* humans[], int length, Human* human);

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
            humans[i] == NULL;
    }

    Human * addHuman(Human * human, int sinsCommited){
        for (int i = 0; i < humanitySize; i++)
        {
            if (humans[i] == NULL)
            {
                humans[i] == human;
                totalSins += sinsCommited;
                break;
            }
        }
        return NULL;
    }
};
struct Demon{
    string type;
    Family * families[lastNamesSize * countriesSize];

    Demon(string _type){
        type = _type;
        for (int i = 0; i < (lastNamesSize * countriesSize); i++)
            families[i] = NULL;
    }

    void printFamilies(){
        for (int i = 0; i < (lastNamesSize * countriesSize); i++)
        {
            if (families[i] != NULL)
            {
                cout << "Country: " << families[i]->country << endl;
                cout << "Last Name: " << families[i]->lastName << endl;
                cout << "Total Sins: " << families[i]->totalSins << endl;
            }
        }
    }

    // Declare a heap structure
    void maxHeapify(int index, int size)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int max = index;
    
        // Checking whether our left or child element
        // is at right index of not to avoid index error
        if (left >= size || left < 0)
            left = -1;
        if (right >= size || right < 0)
            right = -1;
    
        // store left or right element in max if
        // any of these is smaller that its parent
        if (left != -1 && families[left]->totalSins > families[max]->totalSins)
            max = left;
        if (right != -1 && families[right]->totalSins > families[max]->totalSins)
            max = right;
    
        // Swapping the nodes
        if (max != index) {
            Family * temp = families[max];
            families[max] = families[index];
            families[index] = temp;
    
            // recursively calling for their child elements
            // to maintain max heap
            maxHeapify(max, size);
        }
    }
};

void condemnHumans(){

}

int searchDemonIndex(string name){
    for (int i = 0; i < 7; i++)
        if (demons[i] == name)
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

void searchHumansByHigherSin(Demon * demon){
    Human * humans[humanitySize];
    int counter = 0;
    int demonID = searchDemonIndex(demon->type);
    for (int i = 0; i < humanitySize; i++){
        if (humanity[i] != NULL && searchIndexHigherSinByHuman(i) == demonID){
            Human * human = searchHumanByID(i);
            human->state == "HELL";
            //insertInOrderHumans(demon, humans, human, counter++);
            //humans[counter++] = human;
            insertInDescendingOrderHumans(demon, humans, counter++, human);
        }
                
    }
    
    addHumansToFamilies(demon, humans, counter * 0.05);
}

void addHumansToFamilies(Demon * demon, Human * humans[], int size){ // size = total humans
    int stop = (lastNamesSize * countriesSize); // Possibles families
    for (int i = 0; i < size; i++)
    {
        for (int y = 0; y < stop; y++)
        {
            if (demon->families[y] == NULL){
                demon->families[y] = new Family(humans[i]->country, humans[i]->lastName);
                demon->families[y]->addHuman(humans[i], humans[i]->sins[searchDemonIndex(demon->type)]);
                break;
            }
            else if((demon->families[y]->country == humans[i]->country) && (demon->families[y]->lastName == humans[i]->lastName)){
                demon->families[y]->addHuman(humans[i], humans[i]->sins[searchDemonIndex(demon->type)]);
                break;
            }
        }
    }
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