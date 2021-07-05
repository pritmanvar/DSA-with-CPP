// Problem Link : https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1#
    
    vector<vector<bool>> visited; // global vector for track visited cells
    // grid == as mentioned in problem
    // n == number of rows in the grid
    // m == number of coloumns in grid
    // word == word which we have to find
    // indx == index for word from which we have to find
    //      index is x means chars befor x are already founded
    // r == number of row from which we have to start searching in grid
    // c == number of coloumn from which we have to start searching in grid
    // dir = direction in which previous char wad founded
    //      dir is 0 means we have just started to search for the word so there is not any direction for previous char
    
    bool solve(vector<vector<char>> grid, int n, int m, string word, int indx, int r, int c, int dir){
        // we are at the end of word means we already found the word
        if(indx == word.length()){
            return true;
        }
        // we goes out of grid or current cell is visited
        if(r >= n || c >= m || r < 0 || c < 0 || visited[r][c] == true){
            return false;
        }
        
        // we got the char it indx in word at current cell so we will search for next char arround this cell
        if(grid[r][c] == word[indx]){
            visited[r][c] = true; // making current cell visited
            
            
            // if we have same direction as previous one or we are just starting from here(denoted by 0)
            // then and only then we can search in this direction because zig-zag form is not allowd
            // if we found whole word in same direction then we will return true and mark this cell as unvisited to fide other occurrences
            
            if((dir == 0 || dir == 1) && solve(grid,n,m,word,indx+1,r+1,c,1)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 2) && solve(grid,n,m,word,indx+1,r+1,c+1,2)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 3) && solve(grid,n,m,word,indx+1,r,c+1,3)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 4) && solve(grid,n,m,word,indx+1,r-1,c+1,4)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 5) && solve(grid,n,m,word,indx+1,r-1,c,5)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 6) && solve(grid,n,m,word,indx+1,r-1,c-1,6)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 7) && solve(grid,n,m,word,indx+1,r,c-1,7)){
                visited[r][c] = false;
                return true;
            }
            if((dir == 0 || dir == 8) && solve(grid,n,m,word,indx+1,r+1,c-1,8)){
                visited[r][c] = false;
                return true;
            }
        }
        visited[r][c] = false;
        // doesn't find the word so return false
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
        vector<vector<int>> ans;
        
        // clear and resize the visited vector
	    visited.clear();
	    visited.resize(n,vector<bool>(m));
	    
	    // searching for word considiring every cell as begining of word
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            // first char of word is at this cell then and only then we will search for other chars
	            if(grid[i][j] == word[0]){
	                if(solve(grid,n,m,word,0,i,j,0)){ // if we found whole word then add this cell in the answer
	                    ans.push_back({i,j});
	                }
	            }
	        }
	    }
	    
	    return ans;
	}
