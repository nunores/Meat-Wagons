#include <Prisoner.h>
#include "menu.h"
using namespace std;


int showMainMenu(vector<Prisoner> &prisoners)
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
    switch(opt){
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            Prisoner::addPrisoner(prisoners);
            return 2;
        case 3:
            Prisoner::removePrisoner(prisoners);
            return 3;
        case 4:
            showTransportMenu();
        default:
            return -1;
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
        case 0: break;
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

