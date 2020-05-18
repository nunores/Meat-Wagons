#include "misc.h"


#ifdef _WIN32
void clearScreen() {
    system("cls"); system("cls");
}
#endif

#ifdef linux
void clearScreen() {
	system("clear"); system("clear");
}
#endif

void clearBuffer() {
	cin.clear();
	cin.ignore(1000, '\n');
}

bool strIsNumber(string str) {
	if (str.empty()) {
		return false;
	}
	for (unsigned i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]) && str.at(i) != ' ') {
			if (str[i] != '.') {
				return false;
			}
		}
	}
	return true;
}

bool checkNif(int nif) {

    return !(nif < 100000000 || nif > 999999999);
}

void enter_to_exit()
{
	do
	{
		cout << '\n' << "Press enter to continue...";
	} while (cin.get() != '\n');
	clearScreen();
}

bool strIsChar(string str) {
	if (str.size() == 0) {
		return false;
	}
	unsigned non_alfa = 0;
	for (unsigned i = 0; i < str.length(); i++) {
		if (!((str.at(i) <= 'z' && str.at(i) >= 'a') || (str.at(i) <= 'Z' && str.at(i) >= 'A')) && ((str.at(i) != '.') && (str.at(i) != ' '))) {
			return false;
		}
		if (str.at(i) == '.' || str.at(i) == ' ')
			non_alfa++;
	}

    return str.size() != non_alfa;

}






