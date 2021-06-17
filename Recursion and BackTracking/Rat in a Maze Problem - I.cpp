// Problem Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    vector<string> solve(vector<vector<int>> arr, int r, int c, int n, string path, vector<vector<int>> visited){
        if(r == n-1 && c == n-1){ // if we are at destination then we will add path to vector and return that
            vector<string> ans;
            ans.push_back(path);
            return ans;
        }
        
        vector<string> paths; // vector for storing paths till now.
        // calling function recursively for all posibilites
        visited[r][c] = 1;// making this cell visited
        
        if(r+1 < n && arr[r+1][c] == 1 && visited[r+1][c] == 0){
            vector<string> temp;// to store output of recursive call
            temp = solve(arr,r+1,c,n,path+'D',visited);
            paths.insert(paths.end(),temp.begin(),temp.end());
        }
        if(c+1 < n && arr[r][c+1] == 1 && visited[r][c+1] == 0){
            vector<string> temp;
            temp = solve(arr,r,c+1,n,path+'R',visited);
            paths.insert(paths.end(),temp.begin(),temp.end());
        }
        if(r-1 >= 0 && arr[r-1][c] == 1 && visited[r-1][c] == 0){
            vector<string> temp;
            temp = solve(arr,r-1,c,n,path+'U',visited);
            paths.insert(paths.end(),temp.begin(),temp.end());
        }
        if(c-1 >= 0 && arr[r][c-1] == 1 && visited[r][c-1] == 0){
            vector<string> temp;
            temp = solve(arr,r,c-1,n,path+'L',visited);
            paths.insert(paths.end(),temp.begin(),temp.end());
        }
        visited[r][c] = 0;// backTracking
        return paths;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0){ // if 1st element is 0 then we can't move anywhere so return empty vector
            vector<string> temp;
            return temp;
        }
        
        vector<vector<int>> visited(n, vector<int>(n));// Visited array to take care about visited cells
        
        vector<string> ans = solve(m,0,0,n,"",visited);
        sort(ans.begin(),ans.end()); // sorting ans to get desired sequance.
        return ans;
    }
