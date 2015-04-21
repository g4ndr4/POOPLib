#include "Menu.h"


Menu::Menu(Library &l){
	*lib = l;
}


Menu::~Menu(){}


bool Menu::select(){
	cout << "Meni" << endl;
	cout << "1. Uclanjivanje;" << endl;
	cout << "2. Isclanjivanje;" << endl;
	cout << "3. Pozajmljivanje;" << endl;
	cout << "4. Vracanje;" << endl;
	cout << "0. Kraj rada;" << endl;
	int selector = 0;
	cin >> selector;
	if (selector == 1){

	}
	else if (selector == 2){

	}
	else if (selector == 3){

	}
	else if (selector == 4){

	}
	else if (selector == 0){
		selector = 0;
		return true;
	}
	else cout << "*** Nepostojeca opcija!" << endl << endl;
	return false;
}