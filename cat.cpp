#include "cat.h"

Cat::Cat() {
      type = "cat"; // Human, CyberDemon, Balrog, Elf, Cat
      name = "Joe";
      strength = 7;
      hitpoints = 40;
      payoff = 30;
      cost = 500;
}

int Cat::getDamage() {
      int magicChance = rand() % 5 + 1;

      cout << "          Cat Special Ability : Lick Coat, gain 10 hitpoints\n\n";

      hitpoints = hitpoints + 10;

      if (magicChance == 5) {
            cout << "          Cat Scratch! x9 damage\n\n";
            return ((rand() % strength + 1) * 9);
      }
      else
            return (rand() % strength + 1);
};
