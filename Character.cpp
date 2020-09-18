#include "Character_Class.h"
#include <iostream>

	//constructor
	Character::Character(std::string char_name,  int char_hp, int char_dmg ) {
		setName(char_name);
		setHp(char_hp);
		setDamage(char_dmg);
	}
	//destructor
	Character::~Character() {
		std::cout << getName() << " destroyed. \n";
	};
	//setters
	void Character::setName(std::string char_name) {
		name = char_name;
	}
	 void Character::setHp(int char_hp) {
		hp = char_hp;
	}
	void Character::setDamage(int char_dmg) {
		damage = char_dmg;
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
	void Character::attack(Character* const target){
		target->setHp(target->getHp()-getDamage());
	}
	void Character::stat_out () const{
		std::cout <<  getName() << "\t HP: " << getHp() << " , DMG: " << getDamage() <<"\n";
	}
	bool Character::Death(){
		if (getHp()<0){
			setHp(0);
		}
		return getHp()==0;
	}
