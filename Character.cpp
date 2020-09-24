#include "Character.h"
#include <iostream>


Character::Character(std::string char_name,  int char_hp, int char_dmg ) : name(char_name),hp(char_hp), damage(char_dmg) {
}
std::string Character::getName() const {
	return name;
}
int Character::getHp() const {
	return hp;
}
int Character::getDamage() const{
	return damage;
}
void Character::attack(Character&  target) const{
	if (target.getHp() < getDamage()){
		target.hp=0;
	}
	else{
		target.hp-=getDamage();	
	}
}
bool Character::isDead() const{
	return getHp()==0;
}
Character& Character::parseUnit(std::string filename){
	std::ifstream file;
    file.open(filename);
	if (!file.is_open()) throw -99;
	else{
		std::string line;
		std::size_t found;
		std::string name;
		int hp,dmg;
		while (std::getline(file,line)){
  			if (found=line.find("name")!=std::string::npos){
				found=line.find(":");
				name=line.substr(found+2,line.length()-1);
			}
   			else if (found=line.find("hp")!=std::string::npos){
				found=line.find(":");
				hp=std::stoi(line.substr(found+2,line.length()-1));
			}
			else if (found=line.find("dmg")!=std::string::npos){
				found=line.find(":");
				dmg=std::stoi(line.substr(found+2,line.length()-1));
			}
		}
		file.close();
		Character* ptr=new Character(name,hp, dmg);
		return *ptr;
	}
}
std::ostream& operator<<(std::ostream& os, const Character& character){
    os << character.getName() << "\t HP: " << character.getHp() << " , DMG: " << character.getDamage() <<"\n";
    return os;
}	