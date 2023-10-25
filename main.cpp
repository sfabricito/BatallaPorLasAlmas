// Imports
#include "structs/Human.h"

int main(int argc, char const *argv[])
{
    initializeData();

    generateGeneration(3);
    generateGeneration(3);
    generateGeneration(3);
    for (int i = 0; i < humanitySize; i++)
    {
        if (humanity[i] != NULL)
        {
            humanity[i]->print();
            cout << "\033[31m" << "--------------------------------------" << "\033[0m"<< endl;
        }
        
    }
    
    return 0;
}
