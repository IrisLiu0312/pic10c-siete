#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cards.h"

// Global constants
const double THRESHOLD = 7.5; //Max value before busting
const double DTHRESHOLD = 5.5; //dealer's threshold on drawing the next card

int main(){
	//create gamelog.txt
	std::ofstream gamelog;
	gamelog.open("gamelog.txt");
	//Initialize the players and their hands
	Player player(100);
	Player dealer(900);
	Hand play(), deal();
	int round = 1,
		bet = 0,
		win = 0; //player's win
	char reply = 'n';
	double pValue = 0,
		   dValue = 0;

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

		//Draw cards and show hand
		std::cout << "Drawing a card each for player and dealer..." << std::endl;
		play.draw();
		deal.draw();
		//show hand
		std::cout << "Your hand:" << std::endl;
		play.show();

		//continue?
		std::cout << "Draw again (y/n)? ";
		cin >> reply;
		while(reply != 'n'){
			play.draw();
			std::cout << "Your hand:" << std::endl;
			play.show();
			if(play.isBust()){
				std::cout << "Busted! Player has finished drawing." << std::endl;
				break;
			}
			std::cout << "Draw again (y/n)? ";
			cin >> reply;
		}

		//dealer's turn
		std::cout << "Dealer now drawing." << std::endl;
		while(deal.getValue() < DTHRESHOLD)
			deal.draw();
		std::cout << "Dealer has finished drawing." << std::endl;

		//====Calculation====
		//extract values so we don't need to constantly call getValue()
		pValue = play.getValue();
		dValue = deal.getValue();

		//Player busted
		if(play.isBust()){
			//Message
			if(deal.isBust())
				std::cout << "House advantage! Both have busted but you lose. -" << bet << std::endl;
			else
				std::cout << "Busted! You lose. -" << bet << std::endl;
			//Lose money
			player.decrease(bet);
		} //Player DOESN'T bust but dealer does
		else if(deal.isBust()){
			std::cout << "Dealer busted! You win. +" << bet << std::endl;
			player.increase(bet);
			dealer.decrease(bet);
			win = 1;
		} //no one busted, equal value
		else if(pValue == dValue){
			std::cout << "Values are the same, tie. No money is moved." << std::endl;
			win = 2;
		}
		else if(pValue > dValue){
			std::cout << "You have a greater value than the dealer, you win. +" << bet << std::endl;
			player.increase(bet);
			dealer.decrease(bet);
			win = 1;
		} //last case: dealer has more than player
		else{
			std::cout << "The dealer has a greater value than you, you lose. -" << bet << std::endl;
			player.decrease(bet);
		}

		//Current balance
		std::cout << "You now have " << player.balance() << std::endl 
				  << "The dealer has " << dealer.balance() << std::endl;

		//Log everything to gamelog.txt
		gamelog << "====Round " << round << "====" << std::endl
				<< "--Player's hand--" << play.show() << "-----------------" << std::endl
				<< "--Dealer's hand--" << deal.show(); << "----------------" << std::endl;
		switch(win){
			case 0:
				gamelog << "Dealer's win." << std::endl;
				break;
			case 1: 
				gamelog << "Player's win." << std::endl;
				break;
			case 2:
				gamelog << "Tie." << std::endl;
				break;
		}
		gamelog << "Player's balance: " << player.balance() << std::endl
				<< "Dealer's balance: " << dealer.balance() << std::endl
				<< "====End round " << round << "====" << std::endl << std::endl;

		//End round
		std::cout << "====End round " << round << "====" << std::endl << std::endl;
		++round;
	}

	//Game has ended, check for the winner.
	if(player.isBroke())
		std::cout << "You have no more money. You lose." << std::endl;
	else
		std::cout << "The dealer lost $900. You win!" << std::endl;

   return 0;
}
