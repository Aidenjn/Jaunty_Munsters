#include "creature.h"

using namespace std;

// ***** GETTERS *****
int Creature::getStrength() const {
      return strength;
}
int Creature::getHitpoints() const {
      return hitpoints;
}
string Creature::getName() const {
      return name;
}
string Creature::getType() const {
      return type;
}
int Creature::getPayoff() const {
      return payoff;
}
int Creature::getCost() const {
      return cost;
}
int Creature::getDamage() {
      //cout << "CALL GET DAMAGE FUNCTION" << endl;
      // /* initialize random seed: */
      // srand (time(NULL));

      /* returns rand number between 1 and strength: */
      return (rand() % strength + 1);
      //return 20;
}

// ***** SETTERS *****
void Creature::setHitpoints(int newHitpoints) {
      hitpoints = newHitpoints;
}
void Creature::setName(string newName) {
      name = newName;
}
                           
                          