// Problem Link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
    
    void DFS(vector<vector<int>>& graph, vector<bool>& visited,int node, int* backEdges, int par){
        visited[node] = true; // mark current node as visited
        for(int i = 0; i < graph[node].size(); i++){ // running a loop for its children
            if(visited[graph[node][i]] == true){
                if(graph[node][i] != par){ // if current child is visited and it is not its parent then it is a backEdge
                    *backEdges += 1;
                }
            }else{ // if current child is not visited then call DFS for the same
                DFS(graph,visited,graph[node][i],backEdges,node);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int backEdges = 0; // to store number of backEdges
        int com = 0; // to store number of components
        vector<vector<int>> graph(n);
        
        // creating adjacency list
        for(int i = 0; i < connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> visited(n); // vector to mark node as visited
        
        // calling DFS and counting number of connected components
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                DFS(graph,visited,i,&backEdges,-1);
                com++;
            }
        }
        if(backEdges/2 < com-1) // in this case it is not possible to connect all components
            return -1;
        else 
            return com-1;
    }
