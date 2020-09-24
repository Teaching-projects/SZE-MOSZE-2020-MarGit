#include <string>
#include <iostream>
#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H
#include <fstream>
class Character
{
private:
	int hp;
	const int  damage;
	const std::string name;

public:
	Character(std::string char_name, int char_hp, int char_dmg);
	std::string getName() const;
	int getHp() const;
	int getDamage() const;
	void attack(Character& target) const;
	friend std::ostream& operator<<(std::ostream& os, const Character& character);
	bool isDead() const;
	static Character& parseUnit(std::string filename );
};
std::ostream& operator<<(std::ostream& os, const Character& character);
#endif
