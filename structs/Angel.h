#include <cstdlib>
#include <ctime>
#include "Demon.h"

enum AngelName {
    Miguel,
    Nuriel,
    Aniel,
    Rafael,
    Gabriel,
    Shamsiel,
    Raguel,
    Uriel,
    Azrael,
    Sariel,
    NumAngelNames
};

struct Angel {
    AngelName name;            // Nombre del ángel
    int version;            // ID 
    int generation;         // Generación
    Human* savedHuman;      // Puntero al human

    Angel(AngelName _name , int _version, int _generation, Human* human)
        : name(_name), version(_version), generation(_generation), savedHuman(human) {}
};

struct AngelNode {
    Angel* angel;               // Ángel en el nodo actual.
    AngelNode* leftAngel;       //   
    AngelNode* middleAngel;        // 
    AngelNode* rightAngel;         //

    AngelNode(){
        leftAngel = middleAngel = rightAngel = NULL;
    }
};

struct AngelTree {
    AngelNode* root;

    AngelTree() {
        root = NULL;
    }

    int countAngels(AngelNode* node) {
        if (node == NULL) {
            return 0;
        }

        int leftCount = countAngels(node->leftAngel);
        int middleCount = countAngels(node->middleAngel);
        int rightCount = countAngels(node->rightAngel);

        return 1 + leftCount + middleCount + rightCount;
    }

    AngelName getRandomAngelName() {
        // Generate a random angel name within the valid range.
        return static_cast<AngelName>(rand() % NumAngelNames);
    }
    void insert (){
        root = insertAngel(root);
    }

    AngelNode * insertAngel(AngelNode* node) {
        if (node == NULL) {
            
            AngelName randomName = getRandomAngelName();  // Choose a random angel name.
            int calculatedVersion = calculateAngelVersion(root, randomName, generation); // Calculate version per name.
            int calculatedGeneration = getHeight(root); // Calculate generation.
            //Angel* newAngel = new Angel(randomName, calculatedVersion , calculatedGeneration, savedHuman);
            node = new AngelNode();
            //node->angel = newAngel;
            return;
        }

        insertAngel(node->leftAngel);
        insertAngel(node->middleAngel);
        insertAngel(node->rightAngel);
    }

    int getHeight(AngelNode* node) {
        if (node == nullptr) {
            return 0;  // Base case: Height of an empty tree is 0.
        } else {
            // Recursive case: Height is 1 + the maximum height of the child nodes.
            int leftHeight = getHeight(node->leftAngel);
            int midHeight = getHeight(node->middleAngel);
            int rightHeight = getHeight(node->rightAngel);

            return 1 + std::max({leftHeight, midHeight, rightHeight});
        }
    }

    int calculateAngelVersion(AngelNode* root, AngelName name, int generation) {
    if (root == nullptr) {
        return 1; // If this is the first angel of this name in the generation.
    }

    if (root->angel->name == name && root->angel->generation == generation) {
        return 1 + calculateAngelVersion(root->leftAngel, name, generation) +
                   calculateAngelVersion(root->middleAngel, name, generation) +
                   calculateAngelVersion(root->rightAngel, name, generation);
    } else {
        return calculateAngelVersion(root->leftAngel, name, generation) +
                   calculateAngelVersion(root->middleAngel, name, generation) +
                   calculateAngelVersion(root->rightAngel, name, generation);
    }
    }
    Human * HumanSaved(){
        
    }


   void addNewAngelLevel() {
        if (root == nullptr) {
            insertAngel(root);
        } else {
            int currentAngels = countAngels(root);
            int angelsToAdd = 3 * currentAngels;

            for (int i = 0; i < angelsToAdd; i++) {
                insertAngel(root);
            }
        }
    }
};


const int TABLE_SIZE = 1000;


/*struct HashTable {

    list<AngelNode*> table[TABLE_SIZE];

    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

    void insertTreeNode(AngelNode* node, int index) {
        table[index].push_back(node);
    }

    AngelNode* searchTreeNode(int id, int index) {
        for (auto node : table[index]) {
            if (node->angel->savedHuman->id == id) {
                return node;
            }
        }
        return nullptr;
    }


    AngelNode* searchHuman(int id) {
        int index = hashFunction(id);
        return searchTreeNode(id, index);
    }

    void displayBucket(int index) {
        std::cout << "Bucket " << index << ":" << std::endl; // Use std::cout instead of cout.
        for (auto node : table[index]) {
            displayInOrder(node);
        }
    }

    void displayInOrder(AngelNode* node) {
        if (node) {
            displayInOrder(node->leftAngel);
            std::cout << "ID: " << node->angel->savedHuman->id << " Name: " << node->angel->savedHuman->name << std::endl; // Use std::cout instead of cout.
            displayInOrder(node->rightAngel);
        }
    }

    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                displayBucket(i);
            }
        }
    }
};*/