#include <string>
using namespace std;

class Monster
{
public:
	Monster setMonster(Monster x);
	int combatPower;
	string Name;
	~Monster();

private:
	string randomNameGen();

};
