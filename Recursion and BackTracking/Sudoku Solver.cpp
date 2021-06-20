// Problem Link : https://leetcode.com/problems/sudoku-solver/
    bool check(vector<vector<char>> board, int k, int r, int c, vector<int> coloum, vector<int> row, vector<int> sub, char ch){
        
        // calculating the possion in which we have to check that bit is seted or not
        int dig = ch - '1';
        int x = 1 << dig;
        
        // if there is set bit in any array then we will return false
        if((coloum[c]&x) != 0 || (row[r]&x) != 0 || (sub[r/3*3 + c/3]&x) != 0){
            return false;
        } 
        
        return true;
    }
    
    bool solve(vector<vector<char>>& arr,vector<int> fill, int ind, vector<int> coloum, vector<int> row, vector<int> sub){
        // we are at the end of fill means we had successfully filled all empty cells so we will return true.
        if(ind == fill.size()){
            return true;
        }
        
        // calculating row and coloum number from the value of fill array
        int r = fill[ind]/9; 
        int c = fill[ind]%9;
        
        // checking for all possibilities at current possition 
        for(char k = '1'; k <= '9'; k++){
            if(check(arr,k,r,c,coloum,row,sub,k)){ // if current possition is safe for current digit
                // calculating the possion in which we have to set bit
                int dig = k - '1';
                int x = 1 << dig;
                
                // setting bits in currosponding arrays
                coloum[c] |= x;
                row[r] |= x;
                sub[r/3*3 + c/3] |= x;
                arr[r][c] = k; // putting digit at current possion
                // calling for next empty possition and if it returns true means we had found the solution so we will return
                if(solve(arr,fill,ind+1,coloum,row,sub)){ 
                    return true;
                }
                // unsetting bit (BackTracking) 
                coloum[c] ^= x; 
                row[r] ^= x;
                sub[r/3*3 + c/3] ^= x;
                arr[r][c] = '.';
            }
        }
        
        return false;
    }
    
    // Main function
    void solveSudoku(vector<vector<char>>& board) {
        // each cell of coloum will represent one coloum
        // each cell of row will represent one row
        // each cell of sub will represent one 3x3 grid
        // fill will store empty cells of board
        vector<int> fill,coloum(9,0),row(9,0),sub(9,0);
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){// filing fill
                    fill.push_back(i*9 + j); // we can calculate row and coloum number from r*9 + c
                }else{ // we will set bit in currosponding cell of coloum, row or sub
                    int dig = board[i][j] - '1';
                    int x = 1 << dig; // finding the possion in which we have to set bit to mark that this number is already present in the currosponding coloum, row or sub matrix of 3x3
                    
                    coloum[j] |= x;
                    row[i] |= x;
                    sub[i/3*3 + j/3] |= x;
                }
            }
        }
        solve(board,fill,0,coloum,row,sub); // calling to call function
    }
