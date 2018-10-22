#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include <list>
#include <set>
#include <map>
#include <iomanip>
#include <exception>

using namespace std;

class Unit
{
public:

	Unit() : health(20) {}

	Unit(int _a) : health(_a) {}

	void setHealth(int _a) 
	{
		health = _a;
	}

	void showHealth()
	{
		cout << "Unit health: " << health << endl;
	}

protected:

	int health;
};

class Solder: virtual public Unit
{
public:
	Solder() : damage(20), speed(3) {}

	void showDamage()
	{
		cout << "Solder damage: " << damage << endl;
	}

	void showSpeed()
	{
		cout << "Solder speed: " << speed << endl;
	}

protected:

	int damage;
	int speed;
};

class Horse : virtual public Unit
{
public:
	Horse() : speed(20) {}

	void showSpeed() 
	{
		cout << "Horse speed" << speed << endl;
	}

protected:
	int speed;
};

class Horseman : public Horse, public Solder
{
public:

	Horseman() : speed(Horse::speed) {}

	void showSpeed()
	{
		cout << "Horseman speed: " << speed << endl;
	}
private:
	int speed;
};


//class Horseman : public Horse, public Solder {};

//int main() {
//
//	Horseman lancelot;
//
//	lancelot.showSpeed(); // неоднозначность
//
//	cout << endl;
//
//	system("pause");
//
//	return 0;
//}

// неоднозначность решается с помощью двойного использования оператора контекста
// lancelot.::Horse::showSpeed(); 
// но правильно переназначить поле в классе Horseman
int main() {

	Horseman lancelot;

	lancelot.showHealth();

	lancelot.showDamage();

	lancelot.showSpeed();
	
	cout << endl;

	system("pause");

	return 0;
}

