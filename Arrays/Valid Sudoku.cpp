// Problem Link : https://leetcode.com/problems/valid-sudoku/
    bool check(vector<vector<char>> board, int r, int c, char ch){
        for(int i = 0; i < 9; i++){ // checking in the row
            if(i != c && board[r][i] == ch){
                return false;
            }
        }
        for(int i = 0; i < 9; i++){ // checking in the coloum
            if(i != r && board[i][c] == ch){
                return false;
            }
        }
        for(int i = 0; i < 3; i++){ // checking in the 3x3 sub grid 
            for(int j = 0; j < 3; j++){
                if((r/3*3 + i != r || c/3*3 + j != c) && board[r/3*3 + i][c/3*3 + j] == ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){ // checking for every box
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !check(board,i,j,board[i][j])){
                    return false;
                }
            }
        }
        return true;
    }
