// Imports
//#include "structs/Human.h"
#include "structs/Demon.h"
#include <stdio.h>
#include <stdlib.h>

void test();

int main(int argc, char const *argv[])
{
    initializeData();
    lifeTree = new Tree();
    //generateGeneration(1000);
   // generateGeneration(500);
   // generateGeneration(500);
   // generateGeneration(500);
   // generateGeneration(500);
    
    //inOrder(lifeTree->root);
    //cout << height(lifeTree->root) << endl;
    //postByProfession("Engineer", 2); 
    //postByProfession("Doctor", 3);    
    //postByProfession("Teacher", 1);

    return 0;
}


void test(){
    humanity[0] = new Human(0, 1, "ALIVE", "Rosa", "Rivera", "Canada", "Hinduism", "Engineer");   
    humanity[0]->sins[3] = 100;
    humanity[1] = new Human(1, 1, "ALIVE", "Francisco", "Serrano", "Canada", "Hinduism", "Engineer");  
    humanity[1]->sins[3] = 100;
    humanity[2] = new Human(2, 1, "ALIVE", "Maria", "Rivera", "Canada", "Hinduism", "Engineer");
    humanity[2]->sins[3] = 100;  
    humanity[3] = new Human(3, 1, "ALIVE", "Pedro", "Rivera", "Canada", "Hinduism", "Engineer"); 
    humanity[3]->sins[3] = 100; 
    humanity[4] = new Human(4, 1, "ALIVE", "Mario", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[4]->sins[3] = 100;
    humanity[5] = new Human(5, 1, "ALIVE", "Ramon", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[5]->sins[3] = 100;
    humanity[6] = new Human(6, 1, "ALIVE", "Olivia", "Rivera", "Canada", "Hinduism", "Engineer"); 
    humanity[6]->sins[3] = 100; 
    humanity[7] = new Human(7, 1, "ALIVE", "Rosa", "Rivera", "Canada", "Hinduism", "Engineer");   
    humanity[7]->sins[3] = 100;
    humanity[8] = new Human(8, 8, "ALIVE", "Francisco", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[8]->sins[3] = 100;
    humanity[9] = new Human(9, 1, "ALIVE", "Maria", "Rivera", "Canada", "Hinduism", "Engineer");
    humanity[9]->sins[3] = 100;  
    humanity[10] = new Human(10, 1, "ALIVE", "Pedro", "Rivera", "Canada", "Hinduism", "Engineer"); 
    humanity[10]->sins[3] = 100; 
    humanity[11] = new Human(11, 1, "ALIVE", "Mario", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[11]->sins[3] = 100;
    humanity[12] = new Human(12, 1, "ALIVE", "Ramon", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[12]->sins[3] = 80;
    humanity[13] = new Human(13, 1, "ALIVE", "Olivia", "Rivera", "Canada", "Hinduism", "Engineer"); 
    humanity[13]->sins[3] = 100; 
    humanity[14] = new Human(14, 1, "ALIVE", "Rosa", "Rivera", "Canada", "Hinduism", "Engineer");   
    humanity[14]->sins[3] = 100;
    humanity[15] = new Human(15, 15, "ALIVE", "Francisco", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[15]->sins[3] = 100;
    humanity[16] = new Human(16, 1, "ALIVE", "Maria", "Rivera", "Canada", "Hinduism", "Engineer");
    humanity[16]->sins[3] = 120;  
    humanity[17] = new Human(17, 1, "ALIVE", "Pedro", "Rivera", "Canada", "Hinduism", "Engineer"); 
    humanity[17]->sins[3] = 100; 
    humanity[18] = new Human(18, 1, "ALIVE", "Mario", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[18]->sins[3] = 100;
    humanity[19] = new Human(19, 1, "ALIVE", "Ramon", "Rivera", "Canada", "Hinduism", "Engineer");  
    humanity[19]->sins[3] = 100;
    humanity[20] = new Human(20, 1, "ALIVE", "Olivia", "Rivera", "Canada", "Hinduism", "Engineer"); 
    humanity[20]->sins[3] = 100; 
    for (int i = 21; i < 40; i++) {
        humanity[i] = new Human(i, 1, "ALIVE", "John", "Doe", "Canada", "Hinduism", "Engineer");
        humanity[i]->sins[3] = 100;
    }
    
    //postByProfession("Engineer", 3); 
    Demon * demon = new Demon("ABADON");

    searchHumansByHigherSin(demon);

    demon->printFamilies();
}