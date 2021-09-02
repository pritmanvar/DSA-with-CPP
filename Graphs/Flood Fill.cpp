// Problem Link : https://leetcode.com/problems/flood-fill/
    
    // Global array to store all 4 possible directions.
    int dirx[4] = {0,1,0,-1};
    int diry[4] = {-1,0,1,0};
    
    void DFS(vector<vector<int>>& ans, int sr, int sc, int newColor, int oldColor, vector<vector<int>>& visited){
        ans[sr][sc] = newColor; // marking cell with new color
        
        visited[sr][sc] = true; // marking cell as visited
        
        // will try DFS for all four possible directions. 
        for(int i = 0; i < 4; i++){
            int x = sr+dirx[i];
            int y = sc+diry[i];
            // if current cell is vaid then i will call DFS for current cell
            if(x >= 0 && x < ans.size() && y >= 0 && y < ans[0].size() && !visited[x][y] && ans[x][y] == oldColor){
                DFS(ans,x,y,newColor,oldColor,visited);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image; // it will store answer vector
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size())); // visited vector
        
        DFS(ans,sr,sc,newColor,image[sr][sc],visited); // calling for DFS
        
        return ans; // return answer
    }
