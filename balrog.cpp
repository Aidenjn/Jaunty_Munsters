#include "balrog.h"

Balrog::Balrog() {
      type = "balrog"; // Human, CyberDemon, Balrog, Elf, Cat
      name = "Joe";
      strength = 10;
      hitpoints = 100;
      payoff = 50;
      cost = 200;
}

int Balrog::getDamage() {
      //cout << "Balrog Attack" << endl;
      int magicChance = rand() % 10 + 1;
      int damageTotal = 0;

      cout << "          Balarog Special Ability : Fast, + additional attack\n\n";
      for (int i = 0; i < 2; i++) {
            magicChance = rand() % 10 + 1;
            if (magicChance == 10) {
                  cout << "          Demonic Attack! +50 damage\n\n";
                  damageTotal = damageTotal + ((rand() % strength + 1) + 50);
            }
            else
                  damageTotal = damageTotal + (rand() % strength + 1);
      }
      return damageTotal;
}
 
