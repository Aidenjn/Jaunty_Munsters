#pragma once;
#include "demon.h"

Demon::Demon() {
      type = ""; // Human, CyberDemon, Balrog, Elf, Cat
      name = "Demon";
      strength = 10;
      hitpoints = 100;
      payoff = 10;
      cost = 200;
}

int Demon::getDamage() {
      int magicChance = rand() % 10 + 1;

      if (magicChance == 10) {
            cout << "          Demonic Attack! +50 damage\n\n";
            return ((rand() % strength + 1) + 50);
      }
      else
            return (rand() % strength + 1);
}
                                                   