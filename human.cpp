#include "human.h"
#pragma once
// ***** GETTERS *****
// string getType() {
//       return "human";
// }

Human::Human() {
      type = "human"; // Human, CyberDemon, Balrog, Elf, Cat
      name = "Joe";
      strength = 15;
      hitpoints = 100;
      payoff = 300;
      cost = 100;
}

int Human::getDamage() {
      return (rand() % strength + 1);
};
                                          
