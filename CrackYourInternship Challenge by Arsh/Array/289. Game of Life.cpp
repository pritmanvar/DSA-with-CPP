// Problem Link : https://leetcode.com/problems/game-of-life/
class Solution {
public:
    static int count(vector<vector<int>> arr, int r, int c){
        int count = 0;
        if(r-1 >= 0 && arr[r-1][c] == 1){
            count++;
        }
        if(r-1 >= 0 && c-1 >= 0 && arr[r-1][c-1] == 1){
            count++;
        }
        if(c-1 >= 0 && arr[r][c-1] == 1){
            count++;
        }
        if(r+1 < arr.size() && c-1 >= 0 && arr[r+1][c-1] == 1){
            count++;
        }
        if(r+1 < arr.size() && arr[r+1][c] == 1){
            count++;
        }
        if(r+1 < arr.size() && c+1 < arr[0].size() && arr[r+1][c+1] == 1){
            count++;
        }
        if(c+1 < arr[0].size() && arr[r][c+1] == 1){
            count++;
        }
        if(r-1 >= 0 && c+1 < arr[0].size() && arr[r-1][c+1] == 1){
            count++;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int ones = count(temp,i,j);
                if(board[i][j] == 1){
                    if(ones < 2 || ones > 3){
                        board[i][j] = 0;
                    }
                }else{
                    if(ones == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
