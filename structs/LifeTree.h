// Imports
#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

// Prototypes
Human * searchHumanByID(int id);

// Structs
struct Node{
    int id;
    Node * leftNode;
    Node * rightNode;
    Human * human;

    Node(int _id){
        id = _id;
        leftNode = rightNode = NULL;
    }
};

struct Tree{
    Node * root;

    Tree(){
        root = NULL;
    }

    void insert(int id){
        root = insertAux(id, root);
    }

    Node * insertAux(int id, Node * node){
        if (node == NULL)
            return new Node(id);
        else if (node->id < id)
            node->rightNode = insertAux(id, node->rightNode);
        else if (node->id >= id)
            node->leftNode = insertAux(id, node->leftNode);
    
        return node;
    }     
};

void inOrder(Node * node){
    if (node != NULL)
    {
        inOrder(node->leftNode);
        cout << node->id << "  ";
        inOrder(node->rightNode);
    }
}

int maximum (int a, int b)
{
    if (a>b)
    return a;
    else return b;    
}

Human * search (int id, Node * node){
    if (node == NULL)
        return NULL;
    else if (node->id == id && node->human != NULL)
        return node->human;
    else if (node->rightNode == NULL && node->leftNode == NULL){
        if (node->id < id){
            for (int i = node->id; i < humanitySize; i++){
                if(i == id)
                    return humanity[i];
            }
        }
        else{
            for (int i = node->id; i >= 0; i--)
                if(i == id)
                    return humanity[i];
        }
    }
    else if (node->id < id)
        return search(id, node->rightNode);
    else 
        return search(id, node->leftNode);
    return NULL;
}

void addPointerLeaf(Node * root)
{
    if (root == NULL)
        return;
    else if (root->rightNode == NULL && root->leftNode == NULL){
        Human * human = searchHumanByID(root->id);
        root->human = human;
        return;
    }
    addPointerLeaf(root->rightNode);
    addPointerLeaf(root->leftNode);
}

int countNodes(Node * node){
    if (node == NULL)
        return 0;
    else
        return 1+ countNodes(node->rightNode) + countNodes(node->leftNode);
}   

int height (Node * node)
{
    if (node == NULL)
        return -1;
    else 
        return 1 + maximum(height(node->rightNode), height(node->leftNode));
}