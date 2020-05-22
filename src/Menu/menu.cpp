#include <Prisoner.h>
#include "menu.h"
#include "../Point/point.h"
#include "Graph.h"
#include "../Parse/parse.h"

using namespace std;

extern vector<Prisoner> prisoners;

extern Graph<Point> graph;

int showMainMenu()
{
    cout << "================================" << endl;
    cout << "              Menu              " << endl;
    cout << "================================" << endl;
    cout << "1. Ver todos os prisioneiros" << endl;
    cout << "2. Adicionar um prisioneiro" << endl;
    cout << "3. Remover um prisioneiro" << endl;
    cout << "4. Transportar prisioneiro/s" << endl;
    cout << "0. Sair" << endl;
    int opt = choseOption(4);
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
                if(showTransportMenu() == 0)
                    break;
            }

        default:
            return -1;
    }

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
            showDestinationMenu();
            return 0;
        case 2:
            cout << "Loading..." << endl;
            parsePorto();

            return 0;
        case 3:
            cout << "Loading..." << endl;
            parseCoimbra();
            return 0;
        default:
            return -1;

    }
}

int showDestinationMenu()
{
    cout << "================================" << endl;
    cout << "      Selecione um destino      " << endl;
    cout << "================================" << endl;

    //cout << "Destino: ";
    //string line;
    //int dest;
    //getline(cin, line);
    //dest = stoi(line);
    cout << "Carregando..." << endl;
    parseViseu2(prisoners); /////////////////////////////////////////////////////////////////////////////////////////////////////////TODO alterar


    GraphViewer *gc = createGraph();

    while(true){
        string command;
        cout << "Press q to exit!" << endl;
        cin >> command;

        if(command == "q"){
            clearBuffer();
            break;
        }
    }

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
            //break;
        default:
            return -1;
    }
    return 0;
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

