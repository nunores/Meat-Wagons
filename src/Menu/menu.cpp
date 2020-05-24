#include "Prisoner.h"
#include "menu.h"
#include "../Point/point.h"
#include "Graph.h"
#include "../Parse/parse.h"
#include "../Wagon/wagon.h"

using namespace std;

extern vector<Prisoner> prisoners;

extern Graph<Point> graph;

extern vector<Wagon> wagons;

int showMainMenu()
{
    cout << "================================" << endl;
    cout << "              Menu              " << endl;
    cout << "================================" << endl;
    cout << "1. Ver todos os prisioneiros" << endl;
    cout << "2. Adicionar um prisioneiro" << endl;
    cout << "3. Remover um prisioneiro" << endl;
    cout << "4. Visualizar informacoes das carrinhas" << endl;
    cout << "5. Alterar informacoes das carrinhas" << endl;
    cout << "6. Transportar prisioneiro/s" << endl;
    cout << "7. Visualizar mapas disponiveis" << endl;
    cout << "8. Informacoes do ultimo transporte" << endl;
    cout << "0. Sair" << endl;
    int opt = choseOption(8);
    switch (opt) {
        case 0:
            return 0;
        case 1:
            Prisoner::printAllPrisoners();
            return 1;
        case 2:
            Prisoner::addPrisoner();
            return 2;
        case 3:
            Prisoner::removePrisoner();
            return 3;
        case 4:
            while(true){
                if(showWagonInfo() == 0)
                    break;
            }
            return 4;
        case 5:
            while(true){
                if(showSetWagonInfo() == 0)
                    break;
            }
            return 5;

        case 6:
            while(true){
                if(showTransportMenu() == 0)
                    break;
            }
            return 6;
        case 7:
            while(true){
                if(showCompleteMapsMenu() == 0)
                    break;
            }
            return 7;
        case 8:
            while(true){
                if(showTransportInfo() == 0)
                    break;
            }
            return 8;

        default:
            return -1;
    }

}

int showTransportInfo()
{
    cout << "================================" << endl;
    cout << "Informacoes do ultimo transporte" << endl;
    cout << "================================" << endl;
    if (wagons.empty())
    {
        cout << "Nao houve nenhum transporte de prisioneiros recentemente..." << endl;
        enter_to_exit();
        return 0;
    }
    else {
        int n = 1;
        for (Wagon wagon : wagons) {
            cout << n << "." << endl;
            cout << "Destino: " << wagon.getDest() << endl;
            cout << "Distancia percorrida: " << wagon.getDist() << " metros" << endl;
            cout << "Tempo decorrido: " << wagon.getDist() / Wagon::average_speed << " segundos" << endl;
            cout << "Custo da viagem: " << wagon.getDist() * Wagon::cost_per_dist << " €" << endl;
            n++;
        }
        enter_to_exit();
        return 0;
    }
}

int showCompleteMapsMenu()
{
    cout << "================================" << endl;
    cout << "              Mapas             " << endl;
    cout << "================================" << endl;
    cout << "1. Viseu" << endl;
    cout << "2. Porto" << endl;
    cout << "3. Coimbra" << endl;
    cout << "0. Voltar" << endl;
    int opt = choseOption(3);
    switch(opt){
        case 0:
            return 0;
        case 1:
            cout << "Carregando..." << endl;
            graph = Graph<Point>();
            parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
            parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
            parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);
            createGraph();
            while(true){
                string command;
                cout << "Pressione q para sair!" << endl;
                cin >> command;

                if(command == "q"){
                    clearBuffer();
                    break;
                }
            }
            return 1;
        case 2:
            graph = Graph<Point>();
            cout << "Carregando..." << endl;
            parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt", 299610576);
            parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
            parseTags("../Mapas/meat_wagon_tags_porto.txt", 4, 101);
            createGraph();
            while(true){
                string command;
                cout << "Pressione q para sair!" << endl;
                cin >> command;

                if(command == "q"){
                    clearBuffer();
                    break;
                }
            }
            return 2;
        case 3:
            graph = Graph<Point>();
            cout << "Carregando..." << endl;
            parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", 1104700202);
            parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
            parseTags("../Mapas/meat_wagon_tags_coimbra.txt", 4, 212);
            createGraph();
            while(true){
                string command;
                cout << "Pressione q para sair!" << endl;
                cin >> command;

                if(command == "q"){
                    clearBuffer();
                    break;
                }
            }
            return 3;
        default:
            return -1;

    }
}

int showSetWagonInfo()
{
    cout << "=================================" << endl;
    cout << " Altere as seguintes informacoes " << endl;
    cout << "=================================" << endl;
    cout << "Nova capacidade da carrinha: ";
    string info;
    getline(cin, info);
    while(!strIsNumber(info))
    {
        cout << "Capacidade invalida" << endl;
        cout << "Nova capacidade da carrinha: ";
        getline(cin, info);
    }
    Wagon::capacity = stoi(info);
    cout << "Nova velocidade media (m/s): ";
    getline(cin, info);
    while(!strIsNumber(info))
    {
        cout << "Velocidade invalida" << endl;
        cout << "Nova velocidade media (m/s): ";
        getline(cin, info);
    }
    Wagon::average_speed = stod(info);
    cout << "Novo custo medio (€/m): ";
    getline(cin, info);
    while(!strIsNumber(info))
    {
        cout << "Custo invalida" << endl;
        cout << "Novo custo medio (€/m): ";
        getline(cin, info);
    }
    Wagon::cost_per_dist = stod(info);
    return 0;
}

int showWagonInfo()
{
    cout << "================================" << endl;
    cout << "    Informacoes das carrinhas   " << endl;
    cout << "================================" << endl;
    cout << "Capacidade: " << Wagon::capacity << endl;
    cout << "Velocidade media: " << Wagon::average_speed << " (m/s)" << endl;
    cout << "Custo medio: " << Wagon::cost_per_dist << " (€/m)" << endl;
    enter_to_exit();
    return 0;
}

int showMapChoice() {
    cout << "================================" << endl;
    cout << "              Mapas             " << endl;
    cout << "================================" << endl;
    cout << "1. Viseu" << endl;
    cout << "2. Porto" << endl;
    cout << "3. Coimbra" << endl;
    cout << "0. Voltar" << endl;
    int opt = choseOption(3);
    switch(opt){
        case 0:
            return 0;
        case 1:
            showDestinationMenuViseu();
            return 1;
        case 2:
            showDestinationMenuPorto();
            return 2;
        case 3:
            showDestinationMenuCoimbra();
            return 3;
        default:
            return -1;

    }
}

int showMapChoice2() {
    cout << "================================" << endl;
    cout << "              Mapas             " << endl;
    cout << "================================" << endl;
    cout << "1. Viseu" << endl;
    cout << "2. Porto" << endl;
    cout << "3. Coimbra" << endl;
    cout << "0. Voltar" << endl;
    int opt = choseOption(3);
    switch(opt){
        case 0:
            return 0;
        case 1:
            showDestinationMenu2Viseu();
            return 1;
        case 2:
            showDestinationMenu2Porto();
            return 2;
        case 3:
            showDestinationMenu2Coimbra();
            return 3;
        default:
            return -1;

    }
}
int showMapChoice3(){
    cout << "================================" << endl;
    cout << "              Mapas             " << endl;
    cout << "================================" << endl;
    cout << "1. Viseu" << endl;
    cout << "2. Porto" << endl;
    cout << "3. Coimbra" << endl;
    cout << "0. Voltar" << endl;
    int opt = choseOption(3);
    switch(opt){
        case 0:
            return 0;
        case 1:
            showDestinationMenu3Viseu();
            return 1;
        case 2:
            showDestinationMenu3Porto();
            return 2;
        case 3:
            showDestinationMenu3Coimbra();
            return 3;
        default:
            return -1;

    }
}

int showDestinationMenuViseu()
{
    cout << "================================" << endl;
    cout << "      Selecione um destino      " << endl;
    cout << "================================" << endl;

    cout << "Destino: ";
    string line;
    int dest;
    getline(cin, line);
    dest = stoi(line);
    cout << "Carregando..." << endl;
    parseViseu(dest, prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;

}

int showDestinationMenuPorto()
{
    cout << "================================" << endl;
    cout << "      Selecione um destino      " << endl;
    cout << "================================" << endl;

    cout << "Destino: ";
    string line;
    int dest;
    getline(cin, line);
    dest = stoi(line);
    cout << "Carregando..." << endl;
    parsePorto(dest, prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;
}

int showDestinationMenuCoimbra()
{
    cout << "================================" << endl;
    cout << "      Selecione um destino      " << endl;
    cout << "================================" << endl;

    cout << "Destino: ";
    string line;
    int dest;
    getline(cin, line);
    dest = stoi(line);
    cout << "Carregando..." << endl;
    parseCoimbra(dest, prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;
}

int showDestinationMenu2Viseu()
{
    cout << "Carregando..." << endl;
    parseViseu2(prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;

}

int showDestinationMenu2Porto()
{
    cout << "Carregando..." << endl;
    parsePorto2(prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;
}

int showDestinationMenu2Coimbra()
{

    cout << "Carregando..." << endl;
    parseCoimbra2(prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;

}

int showDestinationMenu3Viseu()
{

    cout << "Carregando..." << endl;
    parseViseu3(prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;

}

int showDestinationMenu3Porto()
{

    cout << "Carregando..." << endl;
    parsePorto3(prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;

}


int showDestinationMenu3Coimbra()
{

    cout << "Carregando..." << endl;
    parseCoimbra3(prisoners);


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Pressione q para sair!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

    return 0;

}

int showTransportMenu()
{
    cout << "================================" << endl;
    cout << "    Transportar prisioneiro/s   " << endl;
    cout << "================================" << endl;
    cout << "1. Carrinha com capacidade ilimitada" << endl;
    cout << "2. Carrinha com capacidade ilimitada e recolha seletiva" << endl;
    cout << "3. Carrinha com capacidade limitada e recolha seletiva" << endl;
    cout << "0. Voltar" << endl;
    int opt = choseOption(3);
    switch(opt){
        case 0: return 0;
        case 1:
            while(true){
                if(showMapChoice() == 0)
                    break;
            }
            return 1;
        case 2:
            while(true){
                if(showMapChoice2() == 0)
                    break;
            }
            return 2;
        case 3:
            while(true){
                if(showMapChoice3() == 0)
                    break;
            }
            return 3;
        default:
            return -1;
    }
}

int choseOption(int options)
{
    bool error;
    string option;
    do {
        error = false;
        cin.clear();
        getline(cin, option);
        for (int i = 0; i < option.size(); i++) {
            if (isalpha(option[i])) {
                error = true;
                break;
            }
        }
        if (error) {
            cout << "Input invalido" << endl;
        } else {
            if (stoi(option) > options || stoi(option) < 0) {
                error = true;
                cout << "Input invalido" << endl;
            }
        }
    } while (error);
    return stoi(option);
}

