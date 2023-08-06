#include <stdio.h>

void printBoard(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j != 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    int row, col;
    int currentPlayer = 0;
    int moves = 0;

    while (1)
    {
        printBoard(board);
        if (moves == 9 || checkWin(board, 'X') || checkWin(board, 'O'))
        {
            break;
        }

        printf("Player %d, enter your move (row [0-2] and column [0-2]): ", currentPlayer + 1);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            printf("Invalid move! Please enter row and column values between 0 and 2.\n");
            continue;
        }

        if (board[row][col] == ' ')
        {
            board[row][col] = (currentPlayer == 0) ? 'X' : 'O';
            moves++;
            currentPlayer = (currentPlayer + 1) % 2;
        }
        else
        {
            printf("Cell already taken! Try again.\n");
        }
    }

    printBoard(board);
    if (checkWin(board, 'X'))
    {
        printf("Player 1 (X) wins!\n");
    }
    else if (checkWin(board, 'O'))
    {
        printf("Player 2 (O) wins!\n");
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}