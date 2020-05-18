#include "menu.h"
using namespace std;

int showMainMenu()
{
    cout << "================================" << endl;
    cout << "              Menu              " << endl;
    cout << "================================" << endl;
    cout << "1. Ver todos os prisioneiros" << endl;
    cout << "2. Adicionar um prisioneiro" << endl;
    cout << "3. Transportar prisioneiro" << endl;
    cout << "0. Sair" << endl;
    return choseOption(3);
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
            }
        }
        if (error) {
            cout << "Input inválido" << endl;
        } else {
            if (stoi(option) > options || stoi(option) < 0) {
                error = true;
                cout << "Input inválido" << endl;
            }
        }
    } while (error);
    return stoi(option);
}

