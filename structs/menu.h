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
"   ██████╗  █████╗ ████████╗████████╗██╗     ███████╗    ███████╗ ██████╗ ██████╗     ████████╗██╗  ██╗███████╗    ███████╗ ██████╗ ██╗   ██╗██╗     ███████╗"
"██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝    ██╔════╝██╔═══██╗██╔══██╗    ╚══██╔══╝██║  ██║██╔════╝    ██╔════╝██╔═══██╗██║   ██║██║     ██╔════╝"
"██████╔╝███████║   ██║      ██║   ██║     █████╗      █████╗  ██║   ██║██████╔╝       ██║   ███████║█████╗      ███████╗██║   ██║██║   ██║██║     ███████╗"
"██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝      ██╔══╝  ██║   ██║██╔══██╗       ██║   ██╔══██║██╔══╝      ╚════██║██║   ██║██║   ██║██║     ╚════██║"
"██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗    ██║     ╚██████╔╝██║  ██║       ██║   ██║  ██║███████╗    ███████║╚██████╔╝╚██████╔╝███████╗███████║"
"╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝    ╚═╝      ╚═════╝ ╚═╝  ╚═╝       ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝ ╚═════╝  ╚═════╝ ╚══════╝╚══════╝"
                                                                                                                                                          
        "  `._`-._                                           _,-',\n"
        "     `._ `-._        __.-----.__        _,-'  _,\n"
        "        `._  `-._/__.-' `._.-'__.-'__.-'  _, '\n"
        "           `._  `-.__  ._,-'`-._,_.-'  _, '\n"
        "              `._  `#===           ===#'  _, '\n"
        "               `._/)  ._               _.  (\_, '\n"
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
        cout << textoAzul("Menu Principal") << endl;
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
    while (opcion != 3){
        limpiarConsola();
        cout << textoAzul("World Menu") << endl;
        cout << " (1) Create Humans" << endl;
        cout << " (2) Return to main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Ver clientes
                limpiarConsola();
                cout << textoAzul("Clientes") << endl;
                imprimirClientes(clientes);
                continuar();
                break;
            case 2: // Agregar Clientes
                limpiarConsola();
                cout << textoAzul("Agregar Cliente") << endl;
                agregarClientes(clientes);
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





void menuTree(){
    int opcion = 0;
    while (opcion != 3){
        limpiarConsola();
        cout << textoAzul("Tree of Souls Menu") << endl;
        cout << " (1) Print amount of tree levels" << endl;
        cout << " (2) Print amount of nodes" << endl;
        cout << " (3) Print amount of humans in tree  " << endl;
        cout << " (4) Print amount of humans ask  " << endl;
        cout << " (5) Return to main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Imprimir Pedidos
                limpiarConsola();
                cout << textoAzul("Pedidos") << endl;
                imprimirPedidos(prioridadAlta, prioridadMedia, prioridadBaja);
                break;
            case 2: // Agregar pedido
                limpiarConsola();
                cout << textoAzul("Agregar Pedido") << endl;;
                agregarPedido(clientes, productos, prioridadAlta);
                break;
            case 3:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
        continuar();
    }
}




void menuSocialMedia(){
    int opcion = 0;
    while (opcion != 3){
        limpiarConsola();
        cout << textoAzul("Menu Social Media Publications") << endl;;
        cout << " (1) Look for a user and create a post in a certain social media app" << endl;
        cout << " (2) Region post" << endl;
        cout << " (3) Profesion post in multiple apps" << endl;
        cout << " (4) Family post in favorite apps" << endl;
        cout << " (5) Return to main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Encender Balanceador
                balanceador->Reanudar();
                break;
            case 2: // Apagar Balanceador
                balanceador->Pausar();
                break;
            case 3:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
                continuar();
        }
    }
}

void menuHell(){
    int opcion = 0;
    while (opcion != 4){
        limpiarConsola();
        cout << textoAzul("Hell Menu") << endl;
        cout << textoRojo(" (1) Condemn the sinners with a demon") << endl;
        cout << " (2) Return main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoAzul("Productos a Fabricar") << endl;
                imprimirProductosAFabricar(robots[0]->productos ,robots[0]->productosAFabricar);
                continuar();
                break;
            case 2: // Imprimir Fabricadores
                limpiarConsola();
                cout << textoAzul("Fabricadores") << endl;
                imprimirFabricadores(robots);
                continuar();
                break;
            case 3:{
                int robotId = pedirNumero("ID Robot: ");
                while (!(robotId > 0 && robotId < 11 )){
                    cout << "ID Inválido" << endl;
                    robotId = pedirNumero("ID Robot: ");
                }
                menuFabricador(robots, robotId-1);
                break;
            }
            case 4:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
    }
}




void menuHeaven(){
    int opcion = 0;
    while (opcion != 5){
        limpiarConsola();
        cout << textoAzul("Heaven Menu") << endl;
        cout << " (1) Print Heaven" << endl;
        cout << " (2) Return main menu " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:{
                cout << " (A): Categoría A\n (B): Categoría B\n (C): Categoría C\n (D): Todas las categorías" << endl;
                string tipo = pedirString("Ingrese la categoría: ");
                while(tipo != "A" && tipo != "B" && tipo != "C" && tipo != "D"){
                    tipo = pedirString("Ingrese el Tipo: ");
                }
                robots[id]->categoria = tipo;
                break;
            }
            case 2:
                robots[id]->prioridad = !robots[id]->prioridad;
                break;
            case 3:
                robots[id]->Reanudar();
                break;
            case 4:
                robots[id]->Pausar();
                break;
            case 5:
                return;
            default:
                cout << "Option unavailable, please select a valid option" << endl;
        }
    }
}

void menuHuman(){
    int opcion = 0;
    while (opcion != 5){
        limpiarConsola();
        cout << textoAzul("Human Menu") << endl;
        cout << " (1) Search Human through ID" << endl;
        cout << " (2) Search Human through Name and Last Name" << endl;
        cout << " (3) Return to main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoAzul("Productos a Alistar") << endl;
                imprimirProductosAAlistar(picking);
                continuar();
                break;
            case 2:
                limpiarConsola();
                cout << textoAzul("Alistadores") << endl;
                imprimirAlistadores(picking);
                continuar();
                break;
            case 3: // Imprimir Alistadores
                limpiarConsola();
                cout << textoAzul("Lista espera Alistadores") << endl;
                imprimirListaEsperaAlistadores(picking->filaAlistadores);
                continuar();
                break;
            case 4:{
                int alistadorId = pedirNumero("ID Alistador: ");
                while (!(alistadorId > 0 && alistadorId < 7 )){
                    cout << "ID Inválido" << endl;
                    alistadorId = pedirNumero("ID Alistador: ");
                }
                menuAlistador(picking->alistadores[alistadorId]);
                break;
            }
            case 5:
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
        cout << " (3) Return to main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1: // Encender Alistador
                alistador->Reanudar();
                break;
            case 2: // Apagar Alistador
                alistador->Pausar();
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
        cout << " (4) Return to main menu  " << endl;
        opcion = pedirNumero("Selection: ");
        switch (opcion){
            case 1:
                limpiarConsola();
                cout << textoAzul("Pedidos a facturar") << endl;
                imprimirPedidoAFacturar(facturador->pedidosParaFacturar);
                continuar();
                break;
            case 2: // Encender Facturador
                facturador->Reanudar();
                break;
            case 3: // Apagar Facturador
                facturador->Pausar();
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