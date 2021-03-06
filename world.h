#include "iostream"

#include "creature.h" // Base class
#include "human.h" // child of creature
#include "elf.h" // child of creature
#include "balrog.h" // child of demon
#include "cyberDemon.h" // child of demon
#include "cat.h" // child of creature

#pragma once


class World {
private:
      int currency;
      int numCreatures;
      Creature **creatureArray;

public:
      World();
      ~World();
      World(const World &);
	void operator=(const World &);

      // Setters
      int getCurrency();

      // Fight functions
      void combatStatus(int, int);
      void battleDisplay(int, int, int);
      void inflictDamage(int, int);
      void fightCreatures();
      int chooseBet(int, int);
      int battle(int, int);

      // Other functions
      void continueGame();
      void setup();
      void displayCreatures();
      void buyCreatures();
      int promptCreatureType();
      void makeCreature();
      void addCreature();
      void removeCreature(int);

};
                                                                  