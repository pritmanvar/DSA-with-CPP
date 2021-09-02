    // Problem Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
    bool DFS(vector<int> adj[], vector<bool>& visited, int node, int parent){
        visited[node] = true; // marking current node as visited
        
        for(int i = 0; i < adj[node].size(); i++){
            if(visited[adj[node][i]] == true){
                if(adj[node][i] != parent){ // if current child is visited and that is not a parent then this is cycle so return true
                    return true;
                }
            }else{
                // if it is not visited then call dfs for it
                if(DFS(adj,visited,adj[node][i],node))
                    return true;
            }
        }
        return false; // if there is not any cycle then return false
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V); // visited array
        
        // i will call DFS for every node and if any of them will return true then i will return true
        // else at last i will return false
        for(int i = 0; i < V; i++){ 
            if(visited[i] == false){
                if(DFS(adj,visited,i,-1))
                    return true;
            }
        }
        return false;
    }
