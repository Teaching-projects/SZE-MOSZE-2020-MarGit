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
std::ostream& operator<<(std::ostream& os, const Character& character){
    os << character.getName() << "\t HP: " << character.getHp() << " , DMG: " << character.getDamage() <<"\n";
    return os;
}	