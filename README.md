# Tic-Tac-Toe-game
As part of this project, a functional demo of the X and O game was made, implemented on the ESP 32 
microcontroller. 9 RGB LEDs were used, in 3x3 configuration, where a color will represent a certain player. A 
3x3 button array will be used to make a move. We call a move the push of a button and the lighting of the LED 
corresponding to that button until the end of the game. Once a certain move has been made, pressing the same 
button will no longer make sense. The player marked generically in red will always start. When the match is won 
by one of the 2 players, all 9 LEDs flash 3 times, in the color of the winner. If one of the players wins, after the 
LEDs have flashed, they remain lit in the winner's color, and if none wins, the LED array will remain lit, in the 
same pattern as after the last move. The game can be reset via a button at any time during the game, whether 
someone has won, no one has won, or the game is over.
