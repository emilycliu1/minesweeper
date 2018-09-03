# minesweeper
Text-based of Minesweeper, the classic game that can be found online at http://minesweeperonline.com/

I did this project to familiarize myself with C++ before transitioning from a school that teaches primarily in Java to a new school that teaches in C++. I found the assignment online, as a homework for an introductory programming class. I was unable to find the source code, but using the assignment guidelines, I wrote the source code (and the assignment code) myself.

This program creates a randomized board, currently set at size 10x10, with 10 hidden mines or "bombs." The user can input a set of coordinates (row then column) and enter it as a guess or a flag. 
  - A guess will either reveal how many bombs that coordinate "touches" (may be 0) or will reveal that the user triggered a bomb. 
  - A flag will indicate on the board that the user believes a bomb lies under that coordinate.
  
This continues until the user has flagged all ten bombs correctly without triggering any. If the user guesses a bomb at any time, the game is over.
