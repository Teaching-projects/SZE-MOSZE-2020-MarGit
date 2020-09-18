#include <string>
#include <iostream>
#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H


class Character
{
private:
	int hp; const int  damage;
	const std::string name;

public:
	//constructor
	Character(std::string char_name, int char_hp, int char_dmg);
	//getters
	std::string getName() const;
	int getHp() const;
	int getDamage() const;
	//func
	void attack(Character& target) const;
	friend std::ostream& operator<<(std::ostream& os, const Character& character);
	void stat_out() const;
	bool isDead() const;
};


#endif
