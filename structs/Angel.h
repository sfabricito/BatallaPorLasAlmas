#include <cstdlib>
//#include <ctime>
#include "Demon.h"

struct HeavenHashNode {
    int id;
    HeavenHashNode* leftNode;
    HeavenHashNode* rightNode;
    Human* human;
    int height;

    HeavenHashNode(int _id) {
        id = _id;
        leftNode = rightNode = NULL;
        height = 1;
    }
};

struct HashTree {
    HeavenHashNode * root;

    HashTree() {
        root = NULL;
    }

    int getHeight(HeavenHashNode* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(HeavenHashNode* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->leftNode) - getHeight(node->rightNode);
    }

    HeavenHashNode* rightRotate(HeavenHashNode* y) {
        HeavenHashNode* x = y->leftNode;
        HeavenHashNode* T2 = x->rightNode;

        x->rightNode = y;
        y->leftNode = T2;

        y->height = std::max(getHeight(y->leftNode), getHeight(y->rightNode)) + 1;
        x->height = std::max(getHeight(x->leftNode), getHeight(x->rightNode)) + 1;

        return x;
    }

    HeavenHashNode* leftRotate(HeavenHashNode* x) {
        HeavenHashNode* y = x->rightNode;
        HeavenHashNode* T2 = y->leftNode;

        y->leftNode = x;
        x->rightNode = T2;

        x->height = std::max(getHeight(x->leftNode), getHeight(x->rightNode)) + 1;
        y->height = std::max(getHeight(y->leftNode), getHeight(y->rightNode)) + 1;

        return y;
    }

    HeavenHashNode* insertAuxHash(int id, HeavenHashNode* node) {
        if (node == NULL){
            cout << "Creating heaven hash node" << endl;
            searchHumanByID(id)->print();
            return new HeavenHashNode(id);
        }
        if (id < node->id)
            node->leftNode = insertAuxHash(id, node->leftNode);
        else if (id > node->id)
            node->rightNode = insertAuxHash(id, node->rightNode);
        else
            return node; // Duplicate nodes are not allowed


        node->height = 1 + std::max(getHeight(node->leftNode), getHeight(node->rightNode));

        int balance = getBalanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (id < node->leftNode->id) {
                return rightRotate(node);
            }
            else {
                node->leftNode = leftRotate(node->leftNode);
                return rightRotate(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (id > node->rightNode->id) {
                return leftRotate(node);
            }
            else {
                node->rightNode = rightRotate(node->rightNode);
                return leftRotate(node);
            }
        }

        return node;
    }

    void insertHash(int id) {
        cout << "Test1500"<<endl;
        root = insertAuxHash(id, root);
    }

    void inOrder(HeavenHashNode * node) {
        if (node == NULL)
            return;
       inOrder(node->leftNode);
        searchHumanByID(root->id)->print();
        cout << "----------------------------------------------------------------------------------------" << endl;
        inOrder(node->rightNode);

    }

    void printInOrder() {
        inOrder(root);
        cout << endl;
    }

    Human* searchHuman(int id) {
        HeavenHashNode* current = root;
        while (current != NULL) {
            if (current->id == id) {
                return current->human;
            }
            else if (current->id > id) {
                current = current->leftNode;
            }
            else {
                current = current->rightNode;
            }
        }
        return NULL;
    }
};

struct HashTable {

    static const int size = 1000; // Size of the hash table
    HashTree * table[size]; // Array of trees

    HashTable() {
        // Initialize the hash table
        for (int i = 0; i < size; i++) {
            table[i] = new HashTree();
        }
    }

    void printHeaven() {
    for (int i = 0; i < size; i++) {
        cout << "Bucket " << i << ":\n";
        table[i]->printInOrder();
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "<< endl;
    }
    }

    void insertHuman(Human* human) {
        cout << "hOLA" << endl;
        int index = hashFunction(human->id); // Determine the index for the given Human object.
        cout << "hOLA2" << endl;
        table[index]->insertHash(human->id); // Insert the Human ID into the corresponding balanced tree.
        cout << "hOLA3" << endl;
    }

    /*void* searchHumanPrint(int id) {
        int index = hashFunction(id);
        table[index]->searchHuman(id)->print();
    }*/

    int hashFunction(int id) {
        return id % size;
    }
};

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
    God,
    Seraphim, 
    Cherubim,
    Thrones,
    NumAngelNames
};

string generateAngelMessage(int sins, AngelName angelsavename, string angelgeneration);

struct Angel {
    AngelName name;            // Nombre del ángel
    int version;            // ID 
    int generation;         // Generación
    Human* savedHuman;      // Puntero al human

    Angel(AngelName _name , int _version, int _generation, Human* _human)
        : name(_name), version(_version), generation(_generation), savedHuman(_human) {}
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
    int levelCounter;


    AngelTree() {
        root = NULL;
    }


    AngelName getRandomAngelName() {
        return static_cast<AngelName>(rand() % (NumAngelNames-4));
    }

    void insertTotal(){
        if (root == NULL){
            insertInitialAngels();
            levelCounter = 2;
        }
        else{
            addNewAngelLevel();
            heavenRecord->sendRecord("Heaven record", "You can find the records attachment to this mail.");
        }
    }

    void insertInitialAngels() {
        root = new AngelNode(); // Create a root node without an angel.
        root->angel = new Angel(God, 0, 0, NULL);


        root->leftAngel = new AngelNode();
        root->leftAngel->angel = new Angel(Seraphim, 0, 1, NULL);

        root->middleAngel = new AngelNode();
        root->middleAngel->angel = new Angel (Cherubim, 0, 1, NULL);

        root->rightAngel = new AngelNode();
        root->rightAngel->angel = new Angel (Thrones, 0, 1, NULL);

    }

AngelNode* insertAngel2(AngelNode* node, int parentGeneration, int currentGeneration, int maxLevels) {
    if (node == NULL) {
        AngelName randomName = getRandomAngelName();
        int calculatedVersion = calculateAngelVersion(root, randomName, parentGeneration + 1);
        int calculatedGeneration = parentGeneration + 1;

        Angel* newAngel = new Angel(randomName, calculatedVersion, calculatedGeneration, NULL);
        node = new AngelNode();
        node->angel = newAngel;
        Human* savedHuman = findHuman(node->angel);
        if (savedHuman != NULL)
        {
            heaven->insertHuman(savedHuman);
        }
    } else if (currentGeneration < maxLevels) {
        // Recursively update left, middle, and right subtrees.
        node->leftAngel = insertAngel2(node->leftAngel, node->angel->generation, currentGeneration + 1, maxLevels);
        node->middleAngel = insertAngel2(node->middleAngel, node->angel->generation, currentGeneration + 1, maxLevels);
        node->rightAngel = insertAngel2(node->rightAngel, node->angel->generation, currentGeneration + 1, maxLevels);
    }

    return node;
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

    void addNewAngelLevel() {

        insertAngel2(root, getHeight(root), 0, levelCounter++);
    }

    Human * findHuman(Angel * angel){
        Human * humans[humanitySize];
        int sinneramount = -1; // Initialize with a value that cannot be the actual sin count.
        Human * sinner = NULL;
        
        for (int i = 0; i < humanitySize; i++){
            if (humanity[i] != NULL && humanity[i]->state == "HELL"){
                int currentSins = humanity[i]->addSins(); // Calculate sins once, instead of multiple times.
                if (sinner == NULL || currentSins > sinneramount){
                    sinneramount = currentSins;
                    sinner = humanity[i];
                }
            }
        }
        if (sinner != NULL) { // Ensure sinner is not NULL before making modifications.
            sinner->state = "HEAVEN";
            sinner->saviorAngel = angel;
            cout << "Sinner Amount: " <<  sinneramount << endl;
            heavenRecord->insertLog(sinner, generateAngelMessage(sinneramount, angel->name, to_string(angel->generation)));
        }
        return sinner;    
    }
};

string generateAngelMessage(int sins, AngelName angelsavename, string angelgeneration){
    string name;
    switch (angelsavename) {
        case Miguel: name = "Miguel"; break;
        case Nuriel: name = "Nuriel"; break;
        case Aniel: name = "Aniel"; break;
        case Rafael: name = "Rafael"; break;
        case Gabriel: name = "Gabriel"; break;
        case Shamsiel: name = "Shamsiel"; break;
        case Raguel: name = "Raguel"; break;
        case Uriel: name = "Uriel"; break;
        case Azrael: name = "Azrael"; break;
        case Sariel: name = "Sariel"; break;
        case God: name = "God"; break;
        case Seraphim: name = "Seraphim"; break;
        case Cherubim: name = "Cherubim"; break;
        case Thrones: name = "Thrones"; break;
        default: name = "Unknown"; break;
    }
    string message = "Saved on ";
    auto currentTime = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* timeinfo = std::localtime(&time);
    if (timeinfo) {
        std::stringstream ss;
        ss << std::put_time(timeinfo, "%Y-%m-%d");
        message += ss.str();
    }
    message += "saved for " + to_string(sins);
    message += " by " + name;
    message += " generation" +  angelgeneration;
    return message;
}