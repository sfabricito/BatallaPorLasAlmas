// Imports
#include "structs/Human.h"

int main(int argc, char const *argv[])
{
    initializeData();
    Human * humanity[100000];
    for (int i = 0; i < 100000; i++)
        humanity[i] = NULL; 

    createHumans(humanity, 100000);

    cout << humanityCompleted(humanity) << endl;

    return 0;
}
