/* *************************************
   Ricardo Salazar, February 26, 2015

   Interface of a simple Card class
   ************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

   /*
   The values for this type start at 0 and increase by one
   afterwards until they get to SIETE.
   The rank reported by the function Card::get_rank() below is
   the value listed here plus one.
   E.g:
   The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
   The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
   */
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Card {
   public:
      // Constructor assigns random rank & suit to card.
      Card();

      // Accessors
      string get_spanish_suit() const;
      string get_spanish_rank() const;

      /*
         These are the only functions you'll need to code
         for this class. See the implementations of the two
	 functions above to get an idea of how to proceed.
      */
      string get_english_suit() const;
      string get_english_rank() const;

      // Converts card rank to number.
      // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
      int get_rank() const;

      // Compare rank of two cards. E.g: Eight<Jack is true.
      // Assume Ace is always 1.
      // Useful if you want to sort the cards.
      bool operator < (Card card2) const;

      //destructor
      virtual ~Card();
private:
      suit_t suit;
      rank_t rank;
};


class Hand {
   public:
      // A vector of Cards
      Hand();

      /*draws a card, places it in the vector, and adds it to the value.
      @return nothing*/
      void draw();

      /*returns value of the hand.
      @return a double of the total value.*/ 
      double getValue();

      /*Checks whether the hand has busted.
      @return true if busted, else false*/
      bool isBust();

      //destructor
      virtual ~Hand();
   private:
      std::vector<Card> cards;
      double value;
};


class Player {
   public:
      // Constructor.
      // Assigns initial amount of money
      Player(int m);

      /*gets the amount of money player has
      @return int amount*/
      int balance();

      /*increases money by m amount.
      @param m to increase money by*/
      void increase(int m);

      /*decreases money by m amount, with the lower limit being 0.
      @param m to decrease money by*/
      void decrease(int m);

      /*checks if player has m amount
      @param m required money
      @return true if yes, else false*/
      bool canBet(int m);

      /*checks if player has no more money
      @return true if money == 0, else false*/
      bool isBroke();

      //destructor
      virtual ~Player();
   private:
      int money;
};

#endif
