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
	cout << "2 characters with 3 parameters each (name, HP, dmg)\n";
	
	if (argc != 7) {
		cout << argv[0] << " 2 characters with 3-3 parameters\n";
	}
	else {
		// command prompt parameters
		string name1=argv[1], name2=argv[4];
		int hp1=atoi(argv[2]), dmg1=atoi(argv[3]), hp2=atoi(argv[5]), dmg2=atoi(argv[6]);
		
		Character player1 (name1, hp1, dmg1); 
		Character player2 (name2, hp2, dmg2);
		
		auto_combat(player1,player2);
	}
	return 0;
}