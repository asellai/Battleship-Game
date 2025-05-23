# Battleship Game Report 
Author: Aibek kyzy Asel  

### Project Overview  
This project implements a simplified Battleship game on a 7x7 grid. The player guesses the positions of randomly placed ships, aiming to sink them all. Ships are hidden, and feedback ("Hit," "Miss," or "Sunk") is provided for each guess.  



### Key Features  
-Player Input: Row and column guesses.  
-Random Ship Placement:  
  - 1 ship (length 3), 2 ships (length 2), 4 ships (length 1).  
  - Ensures no overlap or adjacency between ships.  
-Game Board: Tracks hits (X), misses (O), and hidden ships (~).  



### Challenges  
1. Valid Ship Placement: Preventing overlaps and ensuring no ships touch, even at corners. Solved by checking all neighboring cells.  
2. Feedback for "Sunk" Ships: Simplified by checking surrounding cells after a hit.  


### Websites Used
-ChatGPT: Helped simplify functions and algorithms.  
-cplusplus.com: For syntax and examples of vectors and file handling.  
-GeeksforGeeks: Referenced for random number generation and validating ship placement.  
-Cyberforum.ru: Inspiration for simplifying conditions using compact logic.
