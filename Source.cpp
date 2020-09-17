#include <iostream>
#include <sstream>
#include "Character_Class.h"

using namespace std;

void auto_combat(Character* const player1, Character* const player2){
	int turn=1;
	bool end=false;
	while (!end){
		player1->stat_out();player2->stat_out();
		switch (turn){
			case 1:
				cout<<player1->getName()<<" -> "<<player2->getName()<<endl;
				player1->attack(player2);
				turn=2;
				if (player2->Death()){
					end=true;
					player1->stat_out();player2->stat_out();	
					cout<< player2->getName()<<" died. "<< player1->getName()<<" wins.\n";
				}
				break;
			case 2:
				cout<<player2->getName()<<" -> "<<player1->getName()<<endl;
				player2->attack(player1);
				turn=1;
				if (player1->Death()){
					end=true;
					player1->stat_out();player2->stat_out();
					cout<< player1->getName()<<" died. "<< player2->getName()<<" wins.\n";
				}
				break;
			default: cerr<<"Turn can only be 1 or 2!";
		}	
	}
}

int main(int argc, char* argv[]) {
	cout << "Program running: " << argv[0] << endl;
	cout << "2 characters with 3 parameters each (name, HP, dmg)\n";
	
	if (argc != 7) {
		cout << argv[0] << " 2 characters with 3-3 parameters\n";
	}
	else {
		// command prompt parameters
		stringstream ss;
		ss << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << " " << argv[5] << " " << argv[6];
		string name1, name2;
		int hp1, hp2, dmg1, dmg2;
		ss >> name1 ; ss >> hp1; ss >> dmg1; ss >> name2; ss >> hp2; ss >> dmg2;
		
		Character* player1=new Character(name1, hp1, dmg1);
		Character* player2=new Character(name2, hp2, dmg2);
		
		auto_combat(player1,player2);
		delete player1;
		delete player2;
	}
	return 0;
}