#include <iostream>
#include <cstdlib>
#include "Character.h"


using namespace std;

void auto_combat(Character& player1, Character& player2){
	int turn=1;
	bool end=false;
	while (!end){
		player1.stat_out();player2.stat_out();
		if (turn==1){
				cout<<player1.getName()<<" -> "<<player2.getName()<<endl;
				player1.attack(player2);
				turn=2;
				if (player2.isDead()){
					end=true;
					player1.stat_out();player2.stat_out();	
					cout<< player2.getName()<<" died. "<< player1.getName()<<" wins.\n";
				}
		}
			else if (turn==2){
				cout<<player2.getName()<<" -> "<<player1.getName()<<endl;
				player2.attack(player1);
				turn=1;
				if (player1.isDead()){
					end=true;
					player1.stat_out();player2.stat_out();
					cout<< player1.getName()<<" died. "<< player2.getName()<<" wins.\n";
				}
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