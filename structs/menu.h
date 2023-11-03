// Includes
#include "iostream"
#include "string"
#include "Angel.h"
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
void menu();
void SocialMediaOptions();
void BeliefOptions();
void ProfessionOptions();
void CountryOptions();
void LastnameOptions();
void menuFamilyPost();
void DemonOptions();
void CalculateWinner();
int CountAlive();
int CountHeaven();
int CountHell();

void linea();
void limpiarConsola();
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
                linea();
                cout << "How many humans do you want to generate?" << endl;
                int amount = pedirNumero("Amount: ");
                generateGeneration(amount);
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
                cout << " Amount of tree levels" << endl;
                //co
                break;
            case 2: // Print amount of nodes
                limpiarConsola();
                cout << textoAzul("Tree Nodes") << endl;;
                cout << " Amount of nodes" << endl;
                //cout << countNodes() << endl;//Corregir
                break;
            case 3: // Print amount of humans
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


void SocialMediaOptions(){
    cout << " (1) Twitter" << endl;
    cout << " (2) Instagram" << endl;
    cout << " (3) Netflix" << endl;
    cout << " (4) Tinder" << endl;
    cout << " (5) Facebook" << endl;
    cout << " (6) LinkedIn" << endl;
    cout << " (7) Pinterest" << endl;

}

void BeliefOptions(){
    cout << " Christianity " << endl;
    cout << " Islam " << endl;
    cout << " Hinduism " << endl;
    cout << " Buddhism " << endl;
    cout << " Atheism " << endl;
}
void ProfessionOptions(){
    cout << " Doctor" << endl;
    cout << " Teacher" << endl;
    cout << " Engineer" << endl;
    cout << " Lawyer" << endl;
    cout << " Architect" << endl;
    cout << " Accountant" << endl;
    cout << " Chef" << endl;
    cout << " Mechanic" << endl;
    cout << " Actor" << endl;
    cout << " Pilot" << endl;
    cout << " Entrepreneur" << endl;
    cout << " Farmer" << endl;
}
void CountryOptions(){
    cout << " (1) USA" << endl;
    cout << " (2) Canada" << endl;
    cout << " (3) Australia" << endl;
    cout << " (4) France" << endl;
    cout << " (5) Germany" << endl;
    cout << " (6) Brazil" << endl;
    cout << " (7) Argentina" << endl;
    cout << " (8) Spain" << endl;
    cout << " (9) Italy" << endl;
    cout << " (10) Singapore" << endl;
    cout << " (11) Sweden" << endl;
    cout << " (12) Belgium" << endl;
    cout << " (13) New Zealand" << endl;
    cout << " (14) Monaco" << endl;
}

void LastnameOptions(){
    cout << " Castillo" << endl;
    cout << " Montenegro" << endl;
    cout << " Valencia" << endl;
    cout << " Delgado" << endl;
    cout << " Rivera" << endl;
    cout << " Serrano" << endl;
    cout << " Alarcón" << endl;
    cout << " Mendoza" << endl;
    cout << " Vargas" << endl;
    cout << " Herrera" << endl;
    cout << " Roman" << endl;
    cout << " Paredes" << endl;
}


void menuSocialMedia(){
    int opcion = 0;
    string option2;
    string option3;
    while (opcion != 5){
        limpiarConsola();
        cout << textoAzul("Menu Social Media Publications") << endl;;
        cout << " (1) Look for a user and create a post in a certain social media app" << endl;
        cout << " (2) Religion Post" << endl;
        cout << " (3) Profesion Post in multiple apps" << endl;
        cout << " (4) Family Post in favorite apps" << endl;
        cout << " (5) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // 
                limpiarConsola();
                cout << textoAzul("User ID") << endl;
                int id = pedirNumero("ID: ");
                if (id < 0 || id > 1000000){
                    cout << "ID out of range" << endl;
                    continuar();
                    break;
                }
                if (searchHumanByID(id) == NULL){
                    cout << "User not found" << endl;
                    continuar();
                    break;
                }
                cout << "Select the social media app you want to post in" << endl;
                SocialMediaOptions();
                int option = pedirNumero("Selection: ");
                if (option < 1 || option > 7){
                    cout << "Option unavailable, please select a valid option" << endl;
                    continuar();
                    break;
                }
                else{
                    postOnSocialMediaByID(id,option);
                }
                break;
            case 2: //
                limpiarConsola();
                cout << textoAzul("Religion") << endl;
                cout << "Select the religion you want to post with" << endl;
                BeliefOptions();
                option2 = pedirString("Selection: ");
                if (option2 != "Christianity" && option2 != "Islam" && option2 != "Hinduism" && option2 != "Buddhism" && option2 != "Atheism"){
                    cout << "Option unavailable, please select a valid option" << endl;
                    continuar();
                    break;
                }
                else{
                    postByReligion(option2);
                }
                break;
            case 3:
                limpiarConsola();
                cout << textoAzul("Profesion") << endl;
                cout << "Select the profession you want to post in" << endl;
                ProfessionOptions();
                option3 = pedirString("Selection: ");
                if (option3 != "Doctor" && option3 != "Teacher" && option3 != "Engineer" && option3 != "Lawyer" && option3 != "Architect" && option3 != "Accountant" && option3 != "Chef" && option3 != "Mechanic" && option3 != "Actor" && option3 != "Pilot" && option3 != "Entrepreneur" && option3 != "Farmer"){
                    cout << "Option unavailable, please select a valid option" << endl;
                    continuar();
                    break;
                }
                else{
                    cout << "Select the amount of social media apps you want to post in" << endl;
                    int amount = pedirNumero("Amount: ");
                    if (amount < 1 || amount > 7){
                        cout << "Option unavailable, please select a valid option" << endl;
                        continuar();
                        break;
                    }
                    postByProfession(option3 ,amount);
                }
                break;
            case 4:
                limpiarConsola();
                cout << textoAzul("Family Post") << endl;
                menuFamilyPost();
            case 5:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}

void menuFamilyPost(){
    int opcion = 0;
    string countryname;
    string lastname;
    while (opcion != 2){
        limpiarConsola();
        cout << textoAzul("Family Post") << endl;;
        cout << " (1) Post by country and last name" << endl;
        cout << " (2) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoAzul("Country and Last Name") << endl;
                cout << "Select the country you want to post in" << endl;
                CountryOptions();
                countryname = pedirString("Selection: ");
                if (countryname != "USA" && countryname != "Canada" && countryname != "Australia" && countryname != "France" && countryname != "Germany" && countryname != "Brazil" && countryname != "Argentina" && countryname != "Spain" && countryname != "Italy" && countryname != "Singapore" && countryname != "Sweden" && countryname != "Belgium" && countryname != "New Zealand" && countryname != "Monaco"){
                    cout << "Option unavailable, please select a valid option" << endl;
                    continuar();
                    break;
                }
                cout << "Select the last name you want to post with" << endl;
                LastnameOptions();
                lastname = pedirString("Selection: ");
                if (lastname != "Castillo" && lastname != "Montenegro" && lastname != "Valencia" && lastname != "Delgado" && lastname != "Rivera" && lastname != "Serrano" && lastname != "Alarcón" && lastname != "Mendoza" && lastname != "Vargas" && lastname != "Herrera" && lastname != "Roman" && lastname != "Paredes"){
                    cout << "Option unavailable, please select a valid option" << endl;
                    continuar();
                    break;
                }
                //limpiarconsola();
                cout << "Select the amount of social media apps you want to post in" << endl;
                    int amount = pedirNumero("Amount: ");
                    if (amount < 1 || amount > 7){
                        cout << "Option unavailable, please select a valid option" << endl;
                        continuar();
                        break;
                }
                else{
                    postByFamily(countryname, lastname, amount);
                }
                break;
            case 4:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}

void DemonOptions(){
    cout << textoRojo(" (1) ASMODEO = Sin = Lust") << endl;
    cout << textoRojo(" (2) BELFEGOR = Sin = Gluttony") << endl;
    cout << textoAzul(" (3) MAMMON = Sin = Greed") << endl;
    cout << textoRojo(" (4) ABADON = Sin = Sloth") << endl;
    cout << textoRojo(" (5) SATAN = Sin = Wrath")<< endl;
    cout << textoRojo(" (6) BELCEBU = Sin = Envy") << endl;
    cout << textoRojo(" (7) LUCIFER = Sin = Pride") << endl;
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
                DemonOptions();
                int option = pedirNumero("Selection: ");
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
                //printHeaven();
                break;
            }
            case 2:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
    }
}

void menuHuman() {
    int opcion = 0;
    string namedecision;  // Declare the variables here
    string lastNamedecision;

    while (opcion != 3) {
        limpiarConsola();
        cout << textoAzul("Human Menu") << endl;
        cout << " (1) Search Human through ID" << endl;
        cout << " (2) Search Human through Name and Last Name" << endl;
        cout << " (3) Return to Main Menu  " << endl;
        opcion = pedirNumero("Selection: ");

        switch (opcion) {
            case 1:
                limpiarConsola();
                cout << textoAzul("Human ID") << endl;
                int id = pedirNumero("ID: ");
                if (id < 0 || id > 1000000) {
                    cout << "ID out of range" << endl;
                    continuar();
                    break;
                }
                if (searchHumanByID(id) == NULL) {
                    cout << "User not found" << endl;
                    continuar();
                    break;
                }
                else {
                    searchHumanByID(id)->print();
                }
                break;

            case 2:
                limpiarConsola();
                cout << textoAzul("Human Name and Last Name") << endl;
                namedecision = pedirString("Name: ");  // Initialize the variables here
                continuar();
                LastnameOptions();
                lastNamedecision = pedirString("Last Name: ");
                if (searchHumanByName(namedecision, lastNamedecision) == NULL) {
                    cout << "User not found" << endl;
                    continuar();
                    break;
                }
                else {
                    searchHumanByName(namedecision, lastNamedecision)->print();
                }
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
                CalculateWinner();
                continuar();
                break;
            case 2: 
                limpiarConsola();
                cout << textoAzul("Total of humans") << endl;
                int aliveCount = CountAlive();
                int heavenCount = CountHeaven();
                int hellCount = CountHell();
                cout << "Alive: " << textoVerde(to_string(aliveCount)) << endl;
                cout << "Heaven: " << textoAzul(to_string(heavenCount)) << endl;
                cout << "Hell: " << textoRojo(to_string(hellCount)) << endl;
                cout << "Total of humans: " << (aliveCount + heavenCount + hellCount) << endl;
                continuar();
                break;
            case 3:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}

void CalculateWinner(){
    if (CountHeaven() > CountHell()){
        cout << "Heaven won the battle" << endl;
    }
    else if (CountHeaven() < CountHell()){
        cout << "Hell won the battle" << endl;
    }
    else{
        cout << "It was a tie" << endl;
    }
}

int Countalive(){
    int aliveamount = 0;
    for (int i = 0; i < 1000000; i++){
        if (searchHumanByID(i) != NULL){
            if (searchHumanByID(i)->state == "ALIVE"){
                aliveamount++;
            }
        }
    }
    cout << "Alive: " << aliveamount << endl;

}
int CountHeaven(){
    int heavenamount = 0;
    for (int i = 0; i < 1000000; i++){
        if (searchHumanByID(i) != NULL){
            if (searchHumanByID(i)->state == "HEAVEN"){
                heavenamount++;
            }
        }
    }
    cout << "Heaven: " << heavenamount << endl;

}

int CountHell(){
    int hellamount = 0;
    for (int i = 0; i < 1000000; i++){
        if (searchHumanByID(i) != NULL){
            if (searchHumanByID(i)->state == "HELL"){
                hellamount++;
            }
        }
    }
    cout << "Hell: " << hellamount << endl;
    return hellamount;
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
                DemonOptions();
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