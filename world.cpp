#include "world.h"

// CONSTRUCTOR
World::World() {
      currency = 100;
      numCreatures = 0;
      creatureArray = new Creature*[numCreatures];
};

// DESTUCTOR
World::~World() {
      if (numCreatures) {
            for (int i = 0; i < numCreatures; i++) {
                  if (creatureArray[i] != NULL)
		          delete creatureArray[i];
            }
	}
      delete [] creatureArray;
};

// COPY CONSTRUCTOR
World::World(const World & other) {
		numCreatures = other.numCreatures;
		creatureArray = new Creature*[numCreatures];;
		for (int i = 0; i < numCreatures; i++)
			creatureArray[i] = other.creatureArray[i];
}


// ASSIGNMENT OPERATOR OVERLOAD

void World::operator=(const World & other) {
	if (numCreatures) // if there are objects in the array
		delete [] creatureArray; // delete array

	// copy constructor
      numCreatures = other.numCreatures;
      creatureArray = new Creature*[numCreatures];;
      for (int i = 0; i < numCreatures; i++)
            creatureArray[i] = other.creatureArray[i];
}

/*********************************************************************
** Function: setup
** Description: Asks the player how much money they would like to start with, then sets the currency to that.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::setup() {
      int newCurrency;
      cout << "Once you lose all your currency you lose the game." << endl;
      cout << "How much currency would you like to start out with?" << endl;
      cout << "Enter currency: ";
      cin >> newCurrency;
      currency = newCurrency;
}

int World::getCurrency() {
      return currency;
}

/*********************************************************************
** Function: continueGame
** Description: Asks player to enter c before proceeding.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::continueGame() {
      cout << "Enter c to continue..." << endl;
      string input;
      while (input != "c") {
            cin >> input;
      }
}

/*********************************************************************
** Function: promptCreatureType
** Description: Asks the player to enter which creature type they would like to purchase.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: int
** Return: creature type
*********************************************************************/
int World::promptCreatureType() {
      cout << string( 50, '\n' );
      int choice;
      cout << "                  MUNSTER TYPES" << endl;
      cout << "             –––––––––––––––––––––––" << endl;
      cout << "              1: \033[1;31mHuman\033[0m         $\033[1;33m100\033[0m\n" << endl;
      cout << "              2: \033[1;32mElf\033[0m           $\033[1;33m150\033[0m\n" << endl;
      cout << "              3: \033[1;36mBalrog\033[0m        $\033[1;33m200\033[0m\n" << endl;
      cout << "              4: \033[1;34mCyberDemon\033[0m    $\033[1;33m300\033[0m\n" << endl;
      cout << "              5: \033[1;35mCat\033[0m           $\033[1;33m500\033[0m\n" << endl;
      cout << "\n\n";
      cout << "Current account balance: $\033[1;33m" << currency << "\033[0m\n" << endl;
      cout << "Enter the number of desired munster type: ";
      cin >> choice;
      return choice;
}

/*********************************************************************
** Function: makeCreature
** Description: creates a new creature to fill the open spot in the creature array.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::makeCreature() {
      int creatureType = promptCreatureType();
      switch (creatureType) {
            case 1: creatureArray[numCreatures - 1] = new Human; break;
            case 2: creatureArray[numCreatures - 1] = new Elf; break;
            case 3: creatureArray[numCreatures - 1] = new Balrog; break;
            case 4: creatureArray[numCreatures - 1] = new CyberDemon; break;
            case 5: creatureArray[numCreatures - 1] = new Cat; break;
      }
      currency = currency - (creatureArray[numCreatures - 1]->getCost());
      string creatureName;
      cout << "Enter the name of your " << creatureArray[numCreatures - 1]->getType() << ": ";
      cin >> creatureName;
      creatureArray[numCreatures - 1]->setName(creatureName);
}

/*********************************************************************
** Function: addCreature
** Description: Makes creature array bigger so that it can fit a new creature.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::addCreature() {
            numCreatures++; // Add 1 to the size of the creature

            Creature **tempArr = NULL;
            tempArr = new Creature*[numCreatures]; // Temp array equals the size of the original array +1

            for (int i = 0; i < (numCreatures - 1); i++) { // Copy creatures over to temp array
                  tempArr[i] = creatureArray[i];
            }

            delete [] creatureArray; // Clear memory by deleting empty array

            creatureArray = tempArr; // Array equals tempArr

            makeCreature();
}

/*********************************************************************
** Function: removeCreature
** Description: Makes creature array smaller after deleting the given creature.
** Parameters: creature being removed
** Pre-Conditions: int
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::removeCreature(int deadCreature) {
            delete creatureArray[deadCreature]; // deleting the dead creature from memory
            numCreatures = numCreatures - 1; // Subtract 1 to the size of the creature

            Creature **tempArr = NULL;
            tempArr = new Creature*[numCreatures]; // Temp array equals the size of the original array -1

            for (int i = 0; i < deadCreature; i++) {
                  tempArr[i] = creatureArray[i];
            }
            // skip copying the non-existing creature
            for (int i = deadCreature + 1; i < numCreatures + 1; i++) {
                  tempArr[i - 1] = creatureArray[i];

            }

            delete [] creatureArray; // Clear memory by deleting empty array

            creatureArray = tempArr; // Array equals tempArr
}

/*********************************************************************
** Function: displayCreatures
** Description: Displays creatures that have been purchased.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::displayCreatures() {
      cout << string( 50, '\n' );
      for (int i = 0; i < numCreatures; i++) {
            cout << "               \033[1;36m" << creatureArray[i]->getName() << "\033[0m" << endl;
            cout << "             –––––––––––––––––––––" << endl;
            cout << "               index: " << i << endl;
            cout << "               type: \033[1;32m" << creatureArray[i]->getType() << "\033[0m" << endl;
            cout << "               hitpoints: \033[1;31m" << creatureArray[i]->getHitpoints() << "\033[0m" << endl;
            cout << "               strength: " << creatureArray[i]->getStrength() << endl;
            cout << "               payoff: " << creatureArray[i]->getPayoff() << endl;
            cout << string( 2, '\n' );
      }
}

/*********************************************************************
** Function: buyCreatures
** Description: Prevents player from purchasing creatures if there is not enough currency to buy the cheapest one.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::buyCreatures() {
      if (currency >= 100) {
                  addCreature();
      }
      else {
            cout << "You need at least $100 to buy a creature!" << endl;
      }
      continueGame();
}

/*********************************************************************
** Function: chooseBet
** Description: Player chooses which creature they think will win the battle.
** Parameters: creature1, creature2
** Pre-Conditions: int, int
** Post-Conditions: int
** Return: number of the creature being bet upon.
*********************************************************************/
int World::chooseBet(int creature1, int creature2) {
      int bet;
      cout << string( 50, '\n' );
      cout << "                  \033[1;32m OPTIONS \033[0m" << endl;
      cout << "             –––––––––––––––––––––" << endl;
      cout << "               1: " << creatureArray[creature1]->getName() << "\n" << endl;
      cout << "               2: " << creatureArray[creature2]->getName() << "\n" << endl;
      cout << "\n\n";
      cout << "Enter the number of the creature you'd like to bet will win: ";
      cin >> bet;
      if(bet == 1)
            return creature1;
      else
            return creature2;
}

/*********************************************************************
** Function: battleDisplay
** Description: Displays a visual image of the stage of battle taking place.
** Parameters: stage, creature1, creature2
** Pre-Conditions: int, int, int
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::battleDisplay(int attack, int creature1, int creature2) {
      cout << string( 50, '\n' );
      switch (attack) {
            case 1:
                  cout << "             o                o\n            /|\\              /|\\\n            / \\              / \\ \n" << endl;
                  cout << "      \t" << creatureArray[creature1]->getName() << "\t\t   " << creatureArray[creature2]->getName() << endl;
                  break;
            case 2:
                  cout << "            _o/             _ o\n              \\__    \033[1;31m——>\033[0m     /\\\n              <             |\\ \n" << endl;
                  cout << "      \t" << creatureArray[creature1]->getName() << "\t\t   " << creatureArray[creature2]->getName() << endl;
                  break;
            case 3:
                  cout << "            o _               \\o_\n            /\\      \033[1;31m<——\033[0m     __/\n            / |               > \n" << endl;
                  cout << "      \t" << creatureArray[creature1]->getName() << "\t\t   " << creatureArray[creature2]->getName() << endl;
                  break;
      }
      cout << string( 2, '\n' );
}

/*********************************************************************
** Function: combatStatus
** Description: Prints the current status of the battle to the screen.
** Parameters: creature1, creature2
** Pre-Conditions: int, int
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::combatStatus(int creature1, int creature2) {
      cout << "          " << creatureArray[creature1]->getName() << " has " << creatureArray[creature1]->getHitpoints() << " hitpoints left." << endl;
      cout << "\n";
      cout << "          " << creatureArray[creature2]->getName() << " has " << creatureArray[creature2]->getHitpoints() << " hitpoints left." << endl;
      cout << string( 2, '\n' );

}

/*********************************************************************
** Function: inflictDamage
** Description: Subtacts hitpoints from creature1 based on the damage caused by creature2.
** Parameters: creature1, creature2
** Pre-Conditions: int, int
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::inflictDamage(int creature1, int creature2) {
      int damage = creatureArray[creature2]->getDamage();
      creatureArray[creature1]->setHitpoints(creatureArray[creature1]->getHitpoints() - damage);
      cout << "          " << creatureArray[creature2]->getName() << " inflicted " << damage << " damage on " << creatureArray[creature1]->getName() << ".\n \n";
}

/*********************************************************************
** Function: battle
** Description: Creatures fight eachother, main combat funtion.
** Parameters: creature1, creature2
** Pre-Conditions: int, int
** Post-Conditions: int
** Return: winning creature
*********************************************************************/
int World::battle(int creature1, int creature2) {
      battleDisplay(1, creature1, creature2);
      continueGame();
      while ((creatureArray[creature1]->getHitpoints() > 0) and (creatureArray[creature2]->getHitpoints() > 0)) {

            battleDisplay(3, creature1, creature2);
            // creature1 attacks creature2
            inflictDamage(creature1, creature2);
            combatStatus(creature1, creature2);
            if (creatureArray[creature1]->getHitpoints() < 1) {
                  cout << "          " << creatureArray[creature1]->getName() << " has been defeated!\n";
                  return creature2;
            }
            continueGame();

            battleDisplay(2, creature1, creature2);
            // creature2 attacks creature1
            inflictDamage(creature2, creature1);
            combatStatus(creature1, creature2);
            if (creatureArray[creature2]->getHitpoints() < 1) {
                  cout << "          " << creatureArray[creature2]->getName() << " has been defeated!\n\n";
                  return creature1;
            }
            continueGame();
      }
}

/*********************************************************************
** Function: fightCreatures
** Description: Setup for the creature fight.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void World::fightCreatures() {
      /* initialize random seed: */
      srand (time(NULL));
      int bet, winner, creature1, creature2;
      displayCreatures();
      cout << "Please enter the index numbers of the munsters you would like to have fight.\nMunster 1: ";
      cin >> creature1;
      cout << "Munster 2: ";
      cin >> creature2;
      bet = chooseBet(creature1, creature2);
      winner = battle(creature1, creature2);
      cout << "          " << creatureArray[winner]->getName() << " won the battle!\n\n\n";
      if (winner == bet) {
            cout << "You won $\033[1;33m" << creatureArray[bet]->getPayoff() << "\033[0m for winning the bet!" << endl;
            currency = currency + creatureArray[bet]->getPayoff();
      }
      else {
            cout << "You lost $\033[1;33m" << creatureArray[bet]->getPayoff() << "\033[0m for losing the bet!" << endl;
            currency = currency - creatureArray[bet]->getPayoff();
      }
      if (winner == creature1)
            removeCreature(creature2);
      else
            removeCreature(creature1);
      continueGame();
}
