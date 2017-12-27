/**
 * Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.

 */


class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0] , j = click[1] ;
        // If the click position is an 'M' change to 'X' and return
        if(board[i][j] == 'M'){
            board[i][j] = 'X';
        }
        // This means that the click position is an 'E'. Recursively update the board
        else
            updateRecurse(board, i, j);
        return board;
    }
private:
        void updateRecurse(vector<vector<char>>& board, int i, int j){
        int num = countAdjacentMines(board, i, j);
        // Set the square to the number of adjacent mines ( if > 0 )
        if(num > 0){
            board[i][j] = (char)(num + '0');
        }
        // Set the square to a revealed blank square 'B' & Recursively update the 8 adjancent squares.
        else{
            board[i][j] = 'B';
            for(int x=i-1; x <= i + 1; x++){
                for(int y=j-1; y <= j + 1; y++){
                    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || (x == i && y == j) || board[x][y] != 'E')
                        continue;
                    updateRecurse(board, x, y);
                }
            }
        }
    }
    int countAdjacentMines(vector<vector<char>>& board, int i, int j){
        int count = 0;
        for(int x=i-1; x <= i + 1; x++){
            for(int y=j-1; y <= j +1; y++){
                if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || (x == i && y == j))
                    continue;
                else if(board[x][y] == 'M'){
                    count++;
                }
            }
        }
        return count;
    }
};