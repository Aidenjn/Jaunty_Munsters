#include "game.h"

using namespace std;

/*********************************************************************
** Function: clearScreen
** Description: Clears the game screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void const Game::clearScreen() const {
	cout << string( 100, '\n' );
}

/*********************************************************************
** Function: welcome
** Description: Displays game title
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void const Game::welcome() const {
      cout << "\033[1;35m     ██╗ █████╗ ██╗   ██╗███╗   ██╗████████╗██╗   ██╗    ███╗   ███╗██╗   ██╗███╗   ██╗███████╗████████╗███████╗██████╗ ███████╗\033[0m" << endl;
      cout << "\033[1;35m     ██║██╔══██╗██║   ██║████╗  ██║╚══██╔══╝╚██╗ ██╔╝    ████╗ ████║██║   ██║████╗  ██║██╔════╝╚══██╔══╝██╔════╝██╔══██╗██╔════╝\033[0m" << endl;
      cout << "\033[1;35m     ██║███████║██║   ██║██╔██╗ ██║   ██║    ╚████╔╝     ██╔████╔██║██║   ██║██╔██╗ ██║███████╗   ██║   █████╗  ██████╔╝███████╗\033[0m" << endl;
      cout << "\033[1;35m██   ██║██╔══██║██║   ██║██║╚██╗██║   ██║     ╚██╔╝      ██║╚██╔╝██║██║   ██║██║╚██╗██║╚════██║   ██║   ██╔══╝  ██╔══██╗╚════██║\033[0m" << endl;
      cout << "\033[1;35m╚█████╔╝██║  ██║╚██████╔╝██║ ╚████║   ██║      ██║       ██║ ╚═╝ ██║╚██████╔╝██║ ╚████║███████║   ██║   ███████╗██║  ██║███████║\033[0m" << endl;
      cout << "\033[1;35m ╚════╝ ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝      ╚═╝       ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚══════╝\033[0m" << endl;
      cout << string( 25, '\n' );
}

/*********************************************************************
** Function: gameOver
** Description: Displays GAME OVER in bright flashy letters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void const Game::gameOver() const {
	cout << "\033[1;35m	 ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ \033[0m" << endl;
	cout << "\033[1;35m	██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\033[0m" << endl;
	cout << "\033[1;35m	██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\033[0m" << endl;
	cout << "\033[1;35m	██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\033[0m" << endl;
	cout << "\033[1;35m	╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\033[0m" << endl;
	cout << "\033[1;35m	 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\033[0m" << endl;
	cout << string( 25, '\n' );
}

/*********************************************************************
** Function: replay
** Description: Asks player if they would like to play again.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: bool
** Return: true or false
*********************************************************************/
bool Game::replay() {
      string response;
      cout << "Would you like to play again?" << endl;
      cout << "Type y/n : ";
      cin >> response;
      if (response == "y")
            return true;
      cout << "Thanks for playing!" << endl;
      return false;
}

/*********************************************************************
** Function: promptChoices
** Description: prompts choices for user to make
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void const Game::promptChoices() const {
      clearScreen();
      cout << "                  \033[1;32m OPTIONS \033[0m" << endl;
      cout << "             –––––––––––––––––––––" << endl;
      cout << "               1: View Munsters\n" << endl;
      cout << "               2: Buy Munsters\n" << endl;
      cout << "               3: Fight Munsters\n" << endl;
      cout << "               4: Quit\n" << endl;
      cout << "\n\n";
      cout << "Enter the number of the choice you'd like to take: ";
}

/*********************************************************************
** Function: play
** Description: Main gameplay function.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void Game::play() {
      gameWorld.setup();
      int choice = 0;
      while (choice != 4) {
            promptChoices();
            cin >> choice;
            switch (choice) {
                  case 1: gameWorld.displayCreatures(); gameWorld.continueGame(); break;
                  case 2: gameWorld.buyCreatures(); break;
                  case 3: gameWorld.fightCreatures(); break;
                  case 4: goto quit;
                  default: cout << "Give me an valid input!" << endl;
            }
		if (gameWorld.getCurrency() < 1)
			goto quit;
      }
      quit: ;
}
                                                                       
