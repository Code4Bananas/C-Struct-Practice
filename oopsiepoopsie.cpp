#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Warrior {
private:
	int attkMax;
	int blocMax;
public:
	std::string name;
	int health;
	Warrior(std::string name, int health, int attkMax, int blockMax){
		this->name = name;
		this->health = health;
		this->attkMax = attkMax;
		this->blockMax = blockMax;
	}
	int Attack() {
		return std::rand() % this->attackMax;
	}
	int Block() {
		return std::rand() % this->blockMax;
	}
};

class Battle {
public:
	static void StartFight(Warrior& warrior1, Warrior& warrior2){
		//loops forever until condition is met
		while(true){
			if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0){
				std::cout << "Game Over\n";
				break;
			}
			if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0){
				std::cout << "Game Over\n";
				break;
			}
		}
	}
	
	static GetAttackResult(Warrior& warriorA, Warrior& warriorN){
		int warriorAAttkAmt = warriorA.Attack();
		int warriorBBlockAmt = warriorA.Block();
		int damage2WarriorB = ceil(warriorAAttkAmt - warriorBBlockAmt);
		//ternary operator to check for negative values
		damage2WarriorB = (damage2WarriorB <= 0) ? 0 : damage2WarriorB;
		warriorB.health = warriorB.health - damage2WarriorB;
		
		printf("%s attacks %s and deal %d damage\n",
				warriorA.name.c_str(),
				warriorB.name.c_str(),
				damage2WarriorB);
		printf("%s is down to %d health\n",
				warriorB.name.c_str(),
				warriorB.health);
		
		if(warriorB.health <== 0){
			printf("%s has Died and %s is Victorious\n",
					WarriorB.name.c_str(),
					WarriorA.name.c_str());
			return "Game Over";
		} else {
			return "Fight Again";
		}
	}
};

int main()
{
	//any time a bunch of random things are going to be happening, random number generation is good
	srand(time(NULL));
	Warrior thor("Thor", 100, 30, 15);
	Warrior hulk("Hulk", 135, 25, 10);
	
	//starts a fight between Hulk and Thor
	Battle::StartFight(thor, hulk);
	
	return 0;
}