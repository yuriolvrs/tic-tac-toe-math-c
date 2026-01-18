# Tic Tac Toe with Math (C)

## Overview
A terminal-based, 3×3 peg game written in C (C99) that combines traditional Tic Tac Toe with numerical strategy.
Players A and B take turns placing pegs numbered 1–9 on the board, while the program tracks row and column sums to determine win conditions.
The game emphasizes modular design, input validation, and dynamic state tracking without using global variables.

## Features
- 3×3 ASCII board display with row and column labels
- Shows all available pegs for the current turn
- Turn-based gameplay between two players (A and B)
- Input validation for peg selection, row, and column
- Tracks sum of each row and column
- Game-over detection:
  - A row/column sum < 15 triggers an immediate loss for the current player
  - Full board completion determines winner based on row/column sums and turn
- Dynamic player switching and winner announcement
- Modular function-based design:
  - `displayBoard()` – Shows current board state
  - `displayPegs()` – Lists available pegs
  - `NextPlayerMove()` – Updates sums and tracks peg placement
  - `isOver()` – Checks if game-over conditions are met
  - `GameOver()` – Announces winner and switches turn

- Language: C (C99)  
- Platform: Terminal / Command Line  
- Compiler: `gcc`

## Project Context
This project was developed as part of **CCDSTRU – Discrete Structures** at De La Salle University.  
It implements a numerical variation of Tic Tac Toe following system specifications with set operations, row/column sum tracking, and turn-based logic.  

Strict constraints were followed, including:  
- No global or static variables for core logic  
- Modular functions with parameter passing  
- Defensive input validation  
- Clear board state and peg management  

## Design Highlights
- Board represented using a 2D array for row/column access
- Peg availability tracked in a separate array (`peg[]`)
- Sum and completion counts tracked for all rows and columns (`points[]` and `complete[]`)
- Game-over logic separated from player input for clarity
- Turn switching and winner determination encapsulated in functions
