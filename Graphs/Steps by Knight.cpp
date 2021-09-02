// Problem Link : https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
    bool isValid(int x, int y, vector<vector<bool>> &visited, int n){
        // if current cell is out of board or it is visited then i will return false else return true
        if(x <= 0 || y <= 0 || x > n || y > n || visited[x][y] == true)
            return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // direction array to move into all 8 directions 
	    int dirx[] = {1,2,2,1,-1,-2,-2,-1};
	    int diry[] = {-2,-1,1,2,2,1,-1,-2};
	    
	    vector<vector<bool>> visited(N+1, vector<bool>(N+1)); // visited array
	    
	    queue<pair<int,int>> q; // queue for BFS
	    int ans = 0; // ans to store minimum moves
	    
	    // BFS
	    q.push({KnightPos[0],KnightPos[1]});
	    visited[KnightPos[0]][KnightPos[1]] = true; // marking KnightPos as visited
	    while(q.empty() == false){
	        int count = q.size();
	        for(int i = 0; i < count; i++){
	            pair<int,int> temp = q.front();
	            q.pop();
	            
	            if(temp.first == TargetPos[0] && temp.second == TargetPos[1]) // if i am at target position then return ans
	                return ans;
	            
	            // add it's all children into queue if they are valid 
	            for(int i = 0; i < 8; i++){
	                int x = temp.first+dirx[i], y = temp.second+diry[i];
	                if(isValid(x,y,visited,N)){
	                    visited[x][y] = true;
	                    q.push({x,y});
	                }
	            }
	        }
            ans++; // updating ans because we have moved a step
	    }
	    return -1;
	}
