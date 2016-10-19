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
/*Checks whether the hand has busted.
@param hand to check
@return true if busted, else false
*/

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

   return 0;
}
