#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)
const double THRESHOLD = 7.5; //Max value before busting

// Non member functions declarations (if any)

// Non member functions implementations (if any)

int main(){
   /*Game progression:
   	Rules
   		> 7.5 = bust
	Beginning:
		Player $ = 100
		Dealer $ = 900
	Every Round
		P makes a bet
		P draw card, D draw card, P cards are shown
		Another card? (draw and repeat until total < 7.5 || no draw)
		Show dealer's cards (who draws only if total < 5.5)
	Calculation
		(P1 > D) || (D bust)
			P wins, P.$ += bet, D.$ -= bet
		(D > P) || (P bust)
			P loses, P.$ -= bet, D.$ += bet
		(P bust) && (D bust) //house advantage
			P loses, P.$ -= bet, D.$ += bet
		(P == D) && (no one bust)
			Tie, nothing happens
	End game
		(P.$ == 0) || (D.$ == 0)
		Input validation may be required.
	*/
	//Initialize the players and their hands
	Player player(100), dealer(900);
	Hand play(), deal();
	int round = 1,
		bet = 0;
	char reply = 'n';

	//Welcome!
	std::cout << "Welcome to Siete Y Medio." << std::endl;
	//Check end game flags: neither player is broke
	while( (!player.isBroke()) || (!dealer.isBroke()) ){
		//Round
		std::cout << "====Round " << round << "====" << std::endl;

		//Bet
		std::cout << "Please make a bet. You have " << player.balance() << ": ";
		cin >> bet;
		//when the player gives an invalid number
		while(!player.canBet(bet)){
			std::cout << "You gave an invalid number. Please make a bet less than "
					  << player.balance() << "and larger than 0: ";
			cin >> bet;
		}

		//Draw cards and show
		std::cout << "Drawing a card each for player and dealer..." << std::endl;
		play.draw();
		deal.draw();


		//End round
		std::cout << "====End round " << round << "====" << std::endl << std::endl;
		++round;
	}

   return 0;
}
