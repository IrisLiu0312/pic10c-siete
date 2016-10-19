#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/*
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break;
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break;
      default: break;
   }

   r = 1 + rand() % 10;
   switch (r) {
      case  1: rank = AS; break;
      case  2: rank = DOS; break;
      case  3: rank = TRES; break;
      case  4: rank = CUATRO; break;
      case  5: rank = CINCO; break;
      case  6: rank = SEIS; break;
      case  7: rank = SIETE; break;
      case  8: rank = SOTA; break;
      case  9: rank = CABALLO; break;
      case 10: rank = REY; break;
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
   string suitName;
   switch (suit) {
      case OROS:
         suitName = "oros";
	 break;
      case COPAS:
         suitName = "copas";
	 break;
      case ESPADAS:
         suitName = "espadas";
	 break;
      case BASTOS:
         suitName = "bastos";
	 break;
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As";
	 break;
      case DOS:
         rankName = "Dos";
	 break;
      case TRES:
         rankName = "Tres";
	 break;
      case CUATRO:
         rankName = "Cuatro";
	 break;
      case CINCO:
         rankName = "Cinco";
	 break;
      case SEIS:
         rankName = "Seis";
	 break;
      case SIETE:
         rankName = "Siete";
	 break;
      case SOTA:
         rankName = "Sota";
	 break;
      case CABALLO:
         rankName = "Caballo";
	 break;
      case REY:
         rankName = "Rey";
	 break;
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
  string suitName;
  switch (suit) {
     case OROS:
        suitName = "Golds";
  break;
     case COPAS:
        suitName = "Cups";
  break;
     case ESPADAS:
        suitName = "Swords";
  break;
     case BASTOS:
        suitName = "Clubs";
  break;
     default: break;
  }
  return suitName;
}

// Accessor: returns a string with the rank of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
  string rankName;
  switch (rank) {
     case AS:
        rankName = "One";
  break;
     case DOS:
        rankName = "Two";
  break;
     case TRES:
        rankName = "Three";
  break;
     case CUATRO:
        rankName = "Four";
  break;
     case CINCO:
        rankName = "Five";
  break;
     case SEIS:
        rankName = "Six";
  break;
     case SIETE:
        rankName = "Seven";
  break;
     case SOTA:
        rankName = "Ten";
  break;
     case CABALLO:
        rankName = "Eleven";
  break;
     case REY:
        rankName = "Twelve";
  break;
     default: break;
  }
  return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
Hand::Hand(){
  //make an empty vector
  std::vector<Card> cards;
  //initialize value as 0.
  value = 0;
}

/*draws a card, places it in the vector, and adds it to the value.
@return nothing*/
void Hand::draw(){
  //draw a card
  Card card();

  //add value of card
  if(card.get_rank() >= 10)
    value += 0.5;
  else
    value += card.get_rank();

  //place card in hand
  cards.push_back(card);
}

/*shows the hand*/
void Hand::show(){
  std::cout << "Current hand: " << std::endl;
  for(size_t i = 0; i < cards.size(); ++i){
    std::cout << cards[i].get_english_suit() << " " << cards[i].get_english_rank() << " or "
              << cards[i].get_spanish_suit() << " " << cards[i].get_spanish_rank() << std::endl;
  }
  std::cout << "Current value: " << getValue() << std::endl;
}

/*returns value of the hand.
@return a double of the total value.*/ 
double Hand::getValue(){
  return value;
}

/*Checks whether the hand has busted.
      @return true if busted, else false*/
bool Hand::isBust(){
  if(getValue() > THRESHOLD)
    return true;
  return false;
}


/* *************************************************
   Player class
   ************************************************* */
//Initializes player with money m
Player::Player(int m) : money(m){}

/*gets the amount of money player has
@return int amount*/
int Player::balance(){
  return money;
}

/*increases money by m amount.
@param m to increase money by*/
void Player::increase(int m){
  money += m;
  return;
}

/*decreases money by m amount, with the lower limit being 0.
@param m to decrease money by*/
void Player::decrease(int m){
  //if money will go negative, just make it 0.
  if((money - m) < 0 ) 
    money = 0;
  else
    money -= m;
  return;
}

/*checks if player has m amount
@param m required money
@return true if yes, else false*/
bool Player::canBet(int m){
  if(m > 0)
    if(money >= m)
      return true;
  return false;
}

/*checks if player has no more money
@return true if money == 0, else false*/
bool Player::isBroke(){
  if(money == 0)
    return true;
  return false;
}