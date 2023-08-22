# C Project 1
## The task is to create a program that takes two or more matrices as input (according to the choice of the user) and performs the desired matrix operation as told by the user. The output must be displayed in the form of a well formatted matrix. The matrix operations to be included are: addition, subtraction, multiplication with a scalar, multiplication with a matrix, division by a scalar, division by a matrix, transpose of a matrix, inverse of a matrix.
### This C code provides a set of matrix operations to the user, including addition, subtraction, scalar multiplication, matrix multiplication, and transpose. The user is prompted to input the dimensions and elements of the first matrix. Based on the user's choice, the code performs the corresponding operation using the given matrices and displays the result.
### To use the code for matrix operations, follow these steps:
#### 1. Input the matrix dimensions: The program will ask you to input the number of rows and columns for the matrix.
#### 2. Enter matrix elements: Input the elements of the first matrix when prompted.
#### 3. Choose the operation: Select the desired matrix operation from the given options (1 for addition, 2 for subtraction, 3 for scalar multiplication, 4 for matrix multiplication, or 5 for transpose).
#### 4. Follow additional prompts: Depending on the operation chosen, you may be asked for additional inputs (e.g., elements of the second matrix or a scalar value).
#### 5. View the result: The program will display the result of the chosen matrix operation.

# C Project 2
## The task is to recreate the famous tiec-tac-toe game or the dots and crosses game using the Python programming language It is NOT necessary to indlude a Graphical User Interface (GUT). The game should be a multiplayer game including two players on a local system. The board of the tic- tac-toe game should be designed carefully in the CLI in a well formatted manner which should be understandable to the common user. 
#### The printBoard function: This function prints the current state of the Tic-Tac-Toe board, including the moves made by each player, along with separators to display the grid.
#### The checkWin function: This function checks whether a given player ('X' or 'O') has won the game. It checks all the rows, columns, and diagonals to determine if there are three consecutive symbols from the same player.
#### The main function: This is the entry point of the program. It initializes the game board, keeps track of the current player (0 for 'X' and 1 for 'O'), and the number of moves made so far.
#### The main game loop: The loop continues until there are no more available moves (9 moves in total) or a player wins. Inside the loop, the board is printed, the current player is prompted to enter their move (row and column), and the move is checked for validity (within the board boundaries and not already taken). If the move is valid, the board is updated with the player's symbol, and the current player is switched.
#### After the loop ends, the final board state is printed, and the winner or draw is determined using the checkWin function. The result is displayed accordingly.

# C Project 3
### This is a menu-driven program that simulates an election voting system. It allows users to store candidate names, input voter details, and conduct voting. The program ensures voter privacy by clearing the screen after each vote and displays the election results, including a tie scenario.
## Features
### 1. Store Candidate Names: The program allows you to store the names of candidates participating in the election.
### 2. Input Voter Details: You can input voter names, addresses, and IDs to maintain a record.
### 3. Conduct Voting: During the main voting process, users can cast their votes for candidates or choose NOTA (None Of The Above).
### 4. Voter Privacy: The command-line interface (CLI) is cleared after each vote to maintain voter anonymity.
### 5. Display Election Results: After voting, the program displays the candidates with the maximum number of votes and declares the winner(s). In case of a tie, all tied candidates are declared winners.

# C Project 4
## This is a simple CLI-based grocery billing system that takes customer details and the details of the goods bought as input. It calculates the total price for each item based on the provided rate and quantity and then displays the bill in a well-formatted table manner to the customer.
## Features
### Accepts customer details (name, contact information, etc.).
### Takes details of goods bought (name, rate, quantity).
### Calculates the price for each item and computes the total bill amount.
### Displays the bill in a well-formatted table with item details and prices.
