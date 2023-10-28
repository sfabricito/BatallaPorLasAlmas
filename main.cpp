// Imports
#include "structs/Human.h"
#include <stdio.h>
#include <stdlib.h>


void dividirArreglo(int arr[], int inicio, int fin);

int main(int argc, char const *argv[])
{
    initializeData();
    lifeTree = new Tree();
    generateGeneration(500);
    generateGeneration(500);
    generateGeneration(500);
    generateGeneration(500);
    generateGeneration(500);
    
    inOrder(lifeTree->root);
    cout << height(lifeTree->root) << endl;

    return 0;
}