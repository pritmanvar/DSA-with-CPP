// Problem Link : https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#
    
    // all 8 possible directions.
    int dirx[8] = {0,-1,-1,-1,0,1,1,1};
    int diry[8] = {-1,-1,0,1,1,1,0,-1};
    
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        visited[row][col] = true; // mark current cell as true
        
        // try to call DFS in all directions
        for(int i = 0; i < 8; i++){
            int x = row+dirx[i];
            int y = col+diry[i];
            
            // if current cell is valid then i will call DFS to that
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1' && visited[x][y] == false){
                DFS(grid,visited,x,y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size())); // visited array
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                // if current cell is not visited and it is an island then i will call DFS to that
                if(visited[i][j] == false && grid[i][j] == '1'){ 
                    ans++; // update ans because it is new island
                    DFS(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
