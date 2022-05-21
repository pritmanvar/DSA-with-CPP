// Problem Link : https://leetcode.com/problems/word-search/

class Solution {
private:
    vector<int> dir;
    bool solve(vector<vector<char>>& board, vector<vector<bool>>& visited, int si, int sj, int n, int m, string word, int wi){
        if(wi == word.length())
            return true;
        
        visited[si][sj] = true;
        for(int i = 0; i < 4; i++){
            if(si+dir[i] < 0 || si+dir[i] >= n || sj+dir[i+1] < 0 || sj+dir[i+1] >= m || visited[si+dir[i]][sj+dir[i+1]])
                continue;
            
            if(board[si+dir[i]][sj+dir[i+1]] == word[wi])
                if(solve(board, visited, si+dir[i], sj+dir[i+1], n, m, word, wi+1))
                    return true;
        }
        visited[si][sj] = false;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        dir = {0,-1,0,1,0};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0])
                    if(solve(board, visited, i, j, n, m, word, 1))
                        return true;
            }
        }
        return false;
    }
};
