/******************************************************
 * ** Program: jaunty_munsters
 * ** Author: Aiden Nelson
 * ** Date: 5/14/2017
 * ** Description: A game of buying, battling, and betting on munsters.
 * ******************************************************/
#include <iostream>
#include <string>
#include "world.h"
#pragma once

class Game {
private:
      World gameWorld;
public:
      void const welcome() const; // Welcome message
      void const gameOver() const; // Game Over message
      void const clearScreen() const; // Clear's the console
      void play(); // Play game
      bool replay();
      void const promptChoices() const;
};
