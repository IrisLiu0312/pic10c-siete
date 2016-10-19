# pic10c-siete
PIC10C Homework 1 - Siete y Medio

Description:
Your program is expected to:
  1) play 'siete y medio' against you
  2) keep a log of the rounds you played against the dealer.
When you run your program, important information about every round should be recorded in the file "gamelog.txt".

Game progression:
   	Rule: Value > 7.5 = bust
	Beginning:
		Player $ = 100
		Dealer $ = 900
	Every Round:
		P makes a bet
		P draw card, D draw card, P cards are shown
		Another card? (draw and repeat until total < 7.5 or no draw)
		Show dealer's cards (who draws only if total < 5.5)
	Calculation:
		(P1 > D) or (D bust)
			P wins, P.$ += bet, D.$ -= bet
		(D > P) or (P bust)
			P loses, P.$ -= bet, D.$ += bet
		(P bust) and (D bust) -house advantage
			P loses, P.$ -= bet, D.$ += bet
		(P == D) and (no one bust)
			Tie, nothing happens
	End game
		(P.$ == 0) or (D.$ == 0)
		Input validation may be required.