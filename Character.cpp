#include "Character.h"
#include <iostream>

//constructor
Character::Character(std::string char_name,  int char_hp, int char_dmg ) : name(char_name),hp(char_hp), damage(char_dmg) {
}
//getters
std::string Character::getName() const {
	return name;
}
int Character::getHp() const {
	return hp;
}
int Character::getDamage() const{
	return damage;
}
//func
void Character::attack(Character&  target) const{
	if (target.getHp() < this->getDamage()){
		target.hp=0;
	}
	else{
		target.hp=target.getHp()-this->getDamage();	
	}
}
//for stat_out
std::ostream& operator<<(std::ostream& os, const Character* const character)
{
    os << character->getName() << "\t HP: " << character->getHp() << " , DMG: " << character->getDamage() <<"\n";
    return os;
}
void Character::stat_out () const{
	std::cout << this;
}
bool Character::isDead() const{
	return getHp()==0;
}
