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
    God,
    Seraphim, 
    Cherubim,
    Thrones,
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
        //generation = 0;
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
        return static_cast<AngelName>(rand() % (NumAngelNames-4));
    }

    void inserttotal(){
        if (root == NULL){
            insertInitialAngels();
        }
        else{
            addNewAngelLevel();
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

    AngelNode * insertAngel(AngelNode* node) {
        if (node == NULL) {
            
            AngelName randomName = getRandomAngelName();  // Choose a random angel name.
            int calculatedVersion = calculateAngelVersion(root, randomName, generation); // Calculate version per name.
            int calculatedGeneration = getHeight(root); // Calculate generation.
            Human* savedHuman = findHuman(node->angel); // Find the human to save.
            Angel* newAngel = new Angel(randomName, calculatedVersion , calculatedGeneration, savedHuman);
            node = new AngelNode();
            node->angel = newAngel;
            return NULL;
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

   void addNewAngelLevel() {
            int currentAngels = countAngels(root);
            int angelsToAdd = 3 * currentAngels;

            for (int i = 0; i < angelsToAdd; i++) {
                insertAngel(root);
            }
        //generation++;
    }

    Human * findHuman(Angel * angel){
        Human * humans[humanitySize];
        int sinneramount;
        Human * sinner = NULL;
        for (int i = 0; i < humanitySize; i++){
            if (humanity[i] != NULL && humanity[i]->state == "HELL"){
                sinneramount = addallSins(humanity[i]);
                if (sinner == NULL){
                    sinner = humanity[i];
                }
                else if (sinneramount > addallSins(sinner)) {
                    sinner = humanity[i];
                }
            }         
        }
        sinner->state = "HEAVEN";
        sinner->saviorAngel = angel;
        heavenRecord->insertLog(sinner, generateMessage(sinneramount,angel->name,to_string(angel->generation)));
        return sinner;    
        }

    int addallSins(Human * human){
        int sinamountTotal = 0;
        for (int i = 0; i < humanitySize; i++){
            if (humanity[i] != NULL){
                sinamountTotal += humanity[i]->addSins();
            }

        }
        return sinamountTotal;    
    }
};

//Necesito agregar un puntero mas al humano (el humano tiene acceso al angel que lo salvo)......

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
    HeavenHashNode* root;

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
        if (node == NULL)
            return new HeavenHashNode(id);

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
        root = insertAuxHash(id, root);
    }

    void inOrder(HeavenHashNode* node) {
        if (node == NULL)
            return;

        inOrder(node->leftNode);
        cout << "Human Info"<< endl;
        cout << node->id << " "; // Print the id of the node
        node->human->print(); // Print the human object (Esta vara deberia ir bien)
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
        std::cout << "Bucket " << i << ":\n";
        table[i]->printInOrder();
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "<< endl;
    }
    }
    
    void insertHuman(Human* human) {
        int index = hashFunction(human->id); // Determine the index for the given Human object.
        table[index]->insertHash(human->id); // Insert the Human ID into the corresponding balanced tree.
    }

    /*void* searchHumanPrint(int id) {
        int index = hashFunction(id);
        table[index]->searchHuman(id)->print();
    }*/

    int hashFunction(int id) {
        return id % size;
    }
};

string generateMessage(int sins, AngelName angelsavename, string angelgeneration){
    string message = "Saved on ";
    auto currentTime = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* timeinfo = std::localtime(&time);
    if (timeinfo) {
        std::stringstream ss;
        ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
        message += ss.str();
    }
    message += "saved for " + sins;
    message += " by " + angelsavename;
    message += " generation" +  angelgeneration;
    return message;
}