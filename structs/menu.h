// Includes
#include "iostream"
#include "string"

using namespace std;

// Prototipos
void imprimirBanner();
void imprimirOpciones();
void menuWorld();
void menuTree();
void menuSocialMedia();
void menuDemons();
void menuHell();
void menuHeaven();
void menuHuman();
void menuWinner();

void continuar();
int pedirNumero(string text);
string pedirString(string text);
int verifyIntPositive(string number);
double verifyDoublePositive(string number);
string textoRojo(string texto);
string textoVerde(string texto);
string textoAzul(string texto);
string textoAmarillo(string texto);

// Funciones

void linea(){
    cout << "---------------------------------------------------------------" << endl; 
}

void continuar(){
    cout << "Presiona 'Enter' para continuar: ";
    string input;
    getline(cin, input);
    linea();
}

void limpiarConsola(){
    #ifdef _WIN32
    std::system("cls");
    #elif _linux_
    std::system("clear");
    #endif
}

void imprimirBanner(){
    std::string banner =
    "          ______             _     ______                    _        \n"
    "         / _____)           | |   (____  \\         _     _  | |       \n"
    "        ( (____   ___  _   _| |    ____)  )_____ _| |_ _| |_| | _____ \n"
    "         \\____ \\ / _ \\| | | | |   |  __  ((____ (_   _|_   _) || ___ |\n"
    "         _____) ) |_| | |_| | |   | |__)  ) ___ | | |_  | |_| || ____|\n"
    "        (______/ \\___/|____/ \\_)  |______/\\_____|  \\__)  \\__)\\__)_____)\n"
    "                                                                      \n"     
                                                   
                 
        "  `._`-._                                           _,-',\n"
        "     `._ `-._        __.-----.__        _,-'  _,\n"
        "        `._  `-._/__.-' `._.-'__.-'__.-'  _, '\n"
        "           `._  `-.__  ._,-'`-._,_.-'  _, '\n"
        "              `._  `#===           ===#'  _, '\n"
        "               `._/)  ._               _.  (\", '\n"
        "               )*'     **.__     __.**     '*(\n"
        "               #  .==..__  \"\"   \"\"  __..==,  #\n"
        "               #   `\"._(_).       .(_)_.\"'   # ";

    std::cout << textoRojo(banner) << std::endl;
    linea();                                                                                            
}
    
void imprimirOpciones(){
    cout << " (1) World Generation" << endl;
    cout << " (2) Tree of Souls" << endl;
    cout << " (3) Social Media Publications" << endl;
    cout << " (4) Demons" << endl;
    cout << " (5) Hell" << endl;
    cout << " (6) Heaven" << endl;
    cout << " (7) Human" << endl;
    cout << " (8) Winner" << endl;
    cout << " (9) Exit  " << endl;
}

void menu(){
    imprimirBanner();
    int opcion = 0;
    while (opcion != 8){
        cout << textoAzul("Main Menu") << endl;
        imprimirOpciones();
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Clientes
                limpiarConsola();
                menuWorld();
                break;
            case 2: // Almacen (Productos)
                limpiarConsola();
                menuTree();
                break;
            case 3: // Pedidos
                limpiarConsola();
                menuSocialMedia();
                break;
            case 4: // Balanceador
                limpiarConsola();
                menuDemons();
                break;
            case 5: // Balanceador
                limpiarConsola();
                menuHell();
                break;
            case 6:
                // Agregar codigo Fabricadores
                limpiarConsola();
                menuHeaven();
                break;
            case 7: // Picking
                limpiarConsola();
                menuHuman();
                break;
            case 8:
                // Agregar codigo Empacador
                limpiarConsola();
                menuWinner();
                break;
            case 9:
                return;
        }
        limpiarConsola();
    }
}

void menuWorld(){
    int opcion = 0;
    while (opcion != 2){
        limpiarConsola();
        cout << textoAzul("World Menu") << endl;
        cout << " (1) Generate Humanity" << endl;
        cout << " (2) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Ver clientes
                limpiarConsola();
                cout << textoAzul("Generate Humanity") << endl;
                //Funcion to generate humanity
                continuar();
                break;
            case 2:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}



void menuTree(){
    int opcion = 0;
    while (opcion != 5){
        limpiarConsola();
        cout << textoAzul("Tree of Souls Menu") << endl;
        cout << " (1) Print amount of tree levels" << endl;
        cout << " (2) Print amount of nodes" << endl;
        cout << " (3) Print amount of humans in tree  " << endl;
        cout << " (4) Print amount of humans ask  " << endl;
        cout << " (5) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Print amount of tree levels
                limpiarConsola();
                cout << textoAzul("Tree Levels") << endl;
                //Funcion to print amount of tree levels
                break;
            case 2: // Print amount of nodes
                limpiarConsola();
                cout << textoAzul("Tree Nodes") << endl;;
                // Funcion to print amount of nodes
                break;
            case 3: // Print amount of humans in tree
                limpiarConsola();
                cout << textoAzul("Humans in Tree") << endl;;
                // Funcion to print amount of humans in tree
                break;
            case 4: // Print humans ask teacher
                limpiarConsola();
                cout << textoAzul("Humans") << endl;
                // Funcion to print humans ask teacher
                break;
            case 5:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
        continuar();
    }
}




void menuSocialMedia(){
    int opcion = 0;
    while (opcion != 5){
        limpiarConsola();
        cout << textoAzul("Menu Social Media Publications") << endl;;
        cout << " (1) Look for a user and create a post in a certain social media app" << endl;
        cout << " (2) Region Post" << endl;
        cout << " (3) Profesion Post in multiple apps" << endl;
        cout << " (4) Family Post in favorite apps" << endl;
        cout << " (5) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // 
                limpiarConsola();
                cout << textoAzul("User ID") << endl;
                break;
            case 2: //
                limpiarConsola();
                cout << textoAzul("Region") << endl;
                break;
            case 3:
                limpiarConsola();
                cout << textoAzul("Profesion") << endl;
                break;
            case 4:
                limpiarConsola();
                cout << textoAzul("Family Post") << endl;
                break;
            case 5:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}

void menuHell(){
    int opcion = 0;
    while (opcion != 2){
        limpiarConsola();
        cout << textoAzul("Hell Menu") << endl;
        cout << textoRojo(" (1) Condemn the sinners with a demon") << endl;
        cout << " (2) Return main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoRojo("Demon of choice") << endl;
                //Function to condemn a sinner
                break;
            case 2:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
    }
}


void menuHeaven(){
    int opcion = 0;
    while (opcion != 2){
        limpiarConsola();
        cout << textoAzul("Heaven Menu") << endl;
        cout << " (1) Print Heaven" << endl;
        cout << " (2) Return main menu " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:{
                limpiarConsola();
                cout << textoAzul("Heaven") << endl;
                //Function to print heaven
                break;
            }
            case 2:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
    }
}

void menuHuman(){
    int opcion = 0;
    while (opcion != 3){
        limpiarConsola();
        cout << textoAzul("Human Menu") << endl;
        cout << " (1) Search Human through ID" << endl;
        cout << " (2) Search Human through Name and Last Name" << endl;
        cout << " (3) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoAzul("Human ID") << endl;
                //Function to search human through ID
                break;
            case 2:
                limpiarConsola();
                cout << textoAzul("Human Name and Last Name") << endl;
                //Function to search human through Name and Last Name
                continuar();
                break;
            case 3:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
    }
}



void menuWinner(){
    int opcion = 0;
    while (opcion != 3){
        limpiarConsola();
        cout << textoAzul("Winner menu") << endl;
        cout << " (1) Who won the battle?" << endl;
        cout << " (2) Total of humans, in Heaven,Hell or Alive" << endl;
        cout << " (3) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: 
                limpiarConsola();
                cout << textoAzul("Winner") << endl;
                //Function to print winner
                continuar();
                break;
            case 2: 
                limpiarConsola();
                cout << textoAzul("Total of humans") << endl;
                //Function to print total of humans
                break;
            case 3:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}



void menuDemons(){
    int opcion = 0;
    while (opcion != 4){
        limpiarConsola();
        cout << textoAzul("Demon Menu") << endl;
        cout << " (1) Display Demons and their sin" << endl;
        cout << " (2) Human Sinners" << endl;
        cout << " (3) Display list of sinners" << endl;
        cout << " (4) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoRojo("Demons") << endl;
                //Function to print demons
                continuar();
                break;
            case 2: 
                limpiarConsola();
                cout << textoRojo("Human Sinners") << endl;
                //Function to print human sinners
                break;
            case 3: 
                limpiarConsola();
                cout << textoRojo("List of sinners") << endl;
                //Function to print list of sinners
                break;
            case 4:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}



// Funciones secundarias

int pedirNumero(string text){
    cout << text;
    string option;
    getline(cin, option);
    int numberVerified = verifyIntPositive(option); 
    if (numberVerified < 1)
        return pedirNumero(text);
    return numberVerified;
}

string pedirString(string text){
    cout << text;
    string option;
    getline(cin, option);
    if (option == "" || option == " "){
        cout << "No puede ser vacío." << endl;
        return pedirString(text);
    }
    return option;
}

int verifyIntPositive(string number){
    try
    {
        return stoi(number);
    }
    catch(const std::exception& e)
    {
        return -1;
    }
}

double verifyDoublePositive(string number){
    try
    {
        return stod(number);
    }
    catch(const std::exception& e)
    {
        return -1;
    }
}

string textoRojo(string texto){
    return "\033[31m" + texto + "\033[0m";
}

string textoVerde(string texto){
    return "\033[32m" + texto + "\033[0m";
}

string textoAzul(string texto){
    return "\033[34m" + texto + "\033[0m";
}

string textoAmarillo(string texto){
    return "\033[33m" + texto + "\033[0m";
}