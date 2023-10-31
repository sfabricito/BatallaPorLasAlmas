// Imports
//#include "structs/Human.h"
#include "structs/Post.h"
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char const *argv[])
{
    initializeData();
    lifeTree = new Tree();
    generateGeneration(500);
   // generateGeneration(500);
   // generateGeneration(500);
   // generateGeneration(500);
   // generateGeneration(500);
    
    inOrder(lifeTree->root);
    //cout << height(lifeTree->root) << endl;
    postByProfession("Engineer", 2); 
    postByProfession("Doctor", 3);    
    postByProfession("Teacher", 1);   


    return 0;
}