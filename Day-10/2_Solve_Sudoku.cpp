#include<bits/stdc++.h>

 bool checkIfValid(int board[9][9], int val, int row, int col)
{
    for(int r=0; r<9; r++)
        if(board[r][col] == val)
            return false;
        
    for(int c=0; c<9; c++)
        if(board[row][c] == val)
            return false;

    row -= (row%3);
    col -= (col%3);

    for(int i=row; i<row+3; i++)
        for(int j=col; j<col+3; j++)
            if(board[i][j] == val)
                return false;
            
    return true;
}

bool solveBoard(int board[9][9], int row, int col)
{
    if(row == 9)
        return true;
    if(col == 9)
        return solveBoard(board, row+1, 0);
    if(board[row][col] != 0)
        return solveBoard(board, row, col+1);
    
    for(int val=1; val<=9; val++)
    {
        if(checkIfValid(board, val, row, col))
        {
            board[row][col] = val;
            if(solveBoard(board, row, col+1))
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

bool isItSudoku(int matrix[9][9])
{
    solveBoard(matrix, 0, 0);
}