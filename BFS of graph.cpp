// Problem Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans; // to store BFS
        vector<bool> visited(V); // to mark node is visited or not
        
        // queue for BFS
        queue<int> q;
        
        // mark 0 as visited and push that into the stack
        visited[0] = true;
        ans.push_back(0);
        
        // BFS
        q.push(0);
        while(q.empty() == false){
            int count = q.size();
            // in the next level there will be count nodes
            for(int i = 0; i < count; i++){
                int temp = q.front(); // get front element
                q.pop();
                
                // add its chindren into queue if they are not visited and also add them in the ans vector
                for(int j = 0; j < adj[temp].size(); j++){
                    if(visited[adj[temp][j]] == false){
                        q.push(adj[temp][j]);
                        visited[adj[temp][j]] = true;
                        ans.push_back(adj[temp][j]);
                    }
                }
            }
        }
        return ans; // return ans
    }
