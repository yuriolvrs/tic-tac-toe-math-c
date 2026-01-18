/* MEMBERS:
Olivares, Marc Yuri G.
Sto. Domingo, Ysabella Skye J.
Tano, Fiona Amaia M.
Section: S20
*/
#include <stdio.h>

// Displays the 3x3 grid, using values in board as a basis
void displayBoard(int board[][3]) {
    int i, j;
    // Display the column labels
    printf("\n ");
    for (i = 4; i <= 6; i++)
        printf("%3d", i);
    printf("\n \n");
    for (i = 0; i < 3; i++) {
        // Display the row labels
        printf("%d | ", i + 1);
        for (j = 0; j < 3; j++) {
            // Put an empty space if unoccupied
            if (!board[i][j])
                printf(" | ");
            else
                printf("%d | ", board[i][j]);
        }
        printf("\n -------------\n");
    }
}

// Displays all available pegs
void displayPegs (int peg[9]) {
    printf("Available pegs: ");
    int i = 0;
    while (i < 9) {
        //0 peg means peg is already on board
        if (peg[i] > 0)
            printf("%d ", peg[i]);
        i++;
    }
    printf("\n");
}

// Calculates the sum of all pegs in every row and column
void NextPlayerMove (int peg[], int row, int col, int curPeg, int points[], int complete[]) {
    int ok = 1;
    int next;
    // add curPeg value to corresponding row's total points
    if (ok) {
        switch (row) {
            case 0: // Top
                points[0] = points [0] + curPeg;
                complete[0]++;
                next = 1;
                break;
            case 1: // Middle
                points[1] = points [1] + curPeg;
                complete [1]++;
                next = 1;
                break;
            case 2: // Bottom
                points[2] = points [2] + curPeg;
                complete[2]++;
                next = 1;
                break;
        }
    }
    // add curPeg value to corresponding column's total points
    if (ok && next) {
        switch (col) {
            case 0: // Left
                points[3] = points [3] + curPeg;
                complete [3]++;
                next = 0;
                ok = 0;
                break;
            case 1: // Center
                points[4] = points [4] + curPeg;
                complete [4]++;
                next = 0;
                ok = 0;
                break;
            case 2: // Right
                points[5] = points [5] + curPeg;
                complete[5]++;
                next = 0;
                ok = 0;
                break;
        }
    }
}

// Returns 1 if the game is over and 0 otherwise
int isover (int complete[], int points[], int *fullBoard) {
    int over = 0;
    int nComplete = 0;
    int i = 0;
    while (!over && i < 6) {
        if (complete[i] == 3) {
            nComplete++;
            // If a full row/column with a sum less than 15 exists, game is over
            if (points[i] < 15)
                over = 1;
        }
        i++;
    }
    // If the board is full, game is over
    if (nComplete == 6) {
        over = 1;
        *fullBoard = 1;
    }
    return over;
}

// Displays winners if the game is over, switches turns otherwise
void GameOver(int over, int *turn, int fullBoard) {
    if (over) {
        // condition 1
        // if player A's turn and there's a complete row/column that's less than 15
        if (*turn == 1 && !fullBoard)
            printf("\nPlayer B wins!\n");
        // Player B's turn and there's a complete row/column less than 15
        else if (*turn == 0 && ! fullBoard)
            printf("\nPlayer A wins!\n");
        // condition 2
        // if Player B's turn and the board is filled with pegs
        else if (*turn == 0 && fullBoard)
            printf("\nPlayer A wins!\n");
        // Player A's turn and the board is filled with pegs
        else if (*turn == 1 && fullBoard)
            printf("\nPlayer B wins!\n");
    } else
        *turn = !(*turn);
}

int main() {
    int board [3][3];
    int i, j;
    // Initialize board values to blank
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = 0;
            
    // Turn pertains to the current player.
    // 1 means player A, and 0 is player B.
    int turn = 1;
    char player = 'A';
    // Pegs are from 1 to 9
    int peg[9];
    for (i = 1; i <= 9; i++)
        peg[i - 1] = i;
        
    // Row, column, and peg for user input
    char cPeg, cRow, cCol;
    int row, col;
    int curPeg;
    int over = 0;
    int points[8]; // total points of each row and column
    
    // initialize point values to 0
    for (i = 0; i < 6; i++)
        points[i] = 0;
    int complete [6]; // to check if row/col is complete
    // initialize complete[] to 0
    for (i = 0; i < 6; i++)
        complete[i] = 0;
        
    int fullBoard = 0; // if board is full
    printf("Tic Tac Toe with Math!\n");
    
    while (!over) {
        displayBoard(board);
        // Get inputs and convert to array indices
        printf("Player %c's turn!\n", player);
        displayPegs (peg);
        printf("Enter peg: ");
        scanf(" %c", &cPeg);
        printf("Enter row number (1-3): ");
        scanf(" %c", &cRow);
        printf("Enter column number (4-6): ");
        scanf(" %c", &cCol);
        
        // Validity checks
        // Check if the row, col, and peg are within range
        if (cRow < '1' || cRow > '3')
            printf("\nRow out of range, try again!\n");
        else if (cCol < '4' || cCol > '6')
            printf("\nColumn out of range, try again!\n");
        else if (cPeg < '1' || cPeg > '9')
            printf("\nPeg out of range, try again!\n");
        else {
            // Convert to array indices if valid
            row = cRow - '1';
            col = cCol - '4';
            curPeg = cPeg - '0';
            
            // Check if occupied or the peg is already placed
            if (board [row][col])
                printf("\nSpace is already occupied, try again!\n");
            else if (!peg [curPeg - 1])
                printf("\nPeg is already on the board, try again!\n");
            else {
                // Place the peg on the board
                board[row][col] = curPeg;
                peg [curPeg - 1] = 0;
                // Calculate for the sum of rows and columns, check if game is over
                NextPlayerMove (peg, row, col, curPeg, points, complete);
                over = isover (complete, points, &fullBoard);
                GameOver (over, &turn, fullBoard);
                
                // Switch players
                if (player == 'A')
                    player = 'B';
                else
                    player = 'A';
            }
        }
    }
    displayBoard(board);
    return 0;
}