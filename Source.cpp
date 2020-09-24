#include <iostream>
#include <cstdlib>
#include "Character.h"

using namespace std;

void print_stat(const Character& player){
	cout<< player;
}

void take_turn (Character& attacker, Character& defender, bool& end){
	cout<<attacker.getName()<<" -> "<<defender.getName()<<endl;
	attacker.attack(defender);
	if (defender.isDead()){
		end=true;
		print_stat(attacker),print_stat(defender);
		cout<< defender.getName()<<" died. "<< attacker.getName()<<" wins.\n";
	}

}

void auto_combat(Character& player1, Character& player2){
	int turn=1;
	bool end=false;
	while (!end){
		print_stat(player1);print_stat(player2);
		if (turn==1){
			take_turn(player1,player2,end);
			turn=2;
		}
		else if (turn==2){
			take_turn(player2,player1,end);
			turn=1;
		}
		else{
			cerr<<"Turn can only be 1 or 2!";
		}
	}	
}

int main(int argc, char* argv[]) {
	cout << "Program running: " << argv[0] << endl;
	cout << "2 files' name\n";
	
	if (argc != 3) {
		cout << argv[0] << "2 files' name\n";;
	}
	else {
		// command prompt parameters
		try {
			Character p1=Character::parseUnit(argv[1]);
			Character p2=Character::parseUnit(argv[2]);
			auto_combat(p1,p2);
		}
		catch (int x){
		if (x==-99) std::cerr<< "Can not open the files!\n";
		else std::cerr<<"Something went wrong!\n";	
		}
	}
	return 0;
}
