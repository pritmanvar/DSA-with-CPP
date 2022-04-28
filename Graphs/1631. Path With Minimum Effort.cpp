// Problem Link : https://leetcode.com/problems/path-with-minimum-effort/

// dijkstra algorithm
class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        if(n == 1 && m == 1)
            return 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // to get lowest effort 
        
        vector<vector<int>> ans(n, vector<int>(m,INT_MAX));
        pq.push({0,0,0});
        
        // BFS
        while(pq.size() > 0){
            vector<int> temp = pq.top();
            pq.pop();

            
            if(temp[0] > ans[temp[1]][temp[2]]) // we found way of minimum effort then current one
                continue;
            
            if(temp[1] == n-1 && temp[2] == m-1) // we are at our destination
                return temp[0];
            
            for(int j = 0; j < 4; j++){ // call adjecents
                int nr = temp[1] + dir[j], nc = temp[2] + dir[j+1]; // new row and column

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) // invalid cell
                    continue;

                int ndiff = max(temp[0], abs(heights[nr][nc]-heights[temp[1]][temp[2]])); // newdiff = effort for current 

                if(ndiff < ans[nr][nc]){ // if new effort is less then add it to queue to proces it
                    ans[nr][nc] = ndiff;
                    pq.push({ndiff,nr,nc});
                }
            }
        }
        return ans[n-1][m-1]; // return ans
        
    }
};
