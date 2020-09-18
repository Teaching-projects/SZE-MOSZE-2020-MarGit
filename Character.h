#include <string>
#include <iostream>
#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H


class Character
{
private:
	int hp, damage;
	std::string name;

public:
	//constructor
	Character(std::string char_name, int char_hp, int char_dmg);
	//destructor
	~Character(); 
	//setters
	void setName(std::string char_name);
	void setHp(int char_hp);
	void setDamage(int char_dmg);
	//getters
	std::string getName() const;
	int getHp() const;
	int getDamage() const;
	//func
	void attack(Character* const target);
	void stat_out() const;
	bool Death();
};



#endif
