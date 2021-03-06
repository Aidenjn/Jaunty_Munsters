#include <iostream>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#pragma once

using namespace std;

class Creature {
private:
      // nothing private
protected:
      string type; // Human, CyberDemon, Balrog, Elf, Cat
      int strength;
      int hitpoints;
      string name = "unknown";
      int payoff;
      int cost;
public:
      // Getters
      int getStrength() const;
      int getHitpoints() const;
      string getName() const;
      string getType() const;
      int getPayoff() const;
      int getCost() const;

      // Setters
      void setName(string);
      void setHitpoints(int);


      // Mutators

      // Other Functions
      virtual int getDamage() /*{return (rand() % strength + 1);}*/;
};
                      
                                                         