#include "elf.h"

Elf::Elf() {
      type = "elf"; // Human, CyberDemon, Balrog, Elf, Cat
      name = "Joe";
      strength = 15;
      hitpoints = 80;
      payoff = 250;
      cost = 150;
}

int Elf::getDamage() {
      int magicChance = rand() % 5 + 1;

      if (magicChance == 5) {
            cout << "          Magic Attack! x2 damage\n\n";
            return ((rand() % strength + 1) * 2);
      }
      else
            return (rand() % strength + 1);
};
