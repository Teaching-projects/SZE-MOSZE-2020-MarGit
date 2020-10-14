#include "Character.h"
#include <iostream>
#include "Json_parser.h"


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
Character Character::parseUnit(const std::string& filename){
	std::string name;
	int hp,dmg;
	std::map<std::string,std::string> data=Json_parser::Parse(filename);
	name=data.at("name");
	hp=std::stoi(data.at("hp"));
	dmg=std::stoi(data.at("dmg"));
	return Character(name, hp, dmg);
}
std::ostream& operator<<(std::ostream& os, const Character& character){
	os <<character.getName()<<" wins. Remaining HP:"<<character.getHp()<<"\n";
	return os;
}	