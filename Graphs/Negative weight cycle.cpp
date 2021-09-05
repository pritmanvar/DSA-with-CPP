// Problem Link : https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
    bool DFS(vector<vector<pair<int,int>>>& graph, vector<bool>& visited, int node, int weight){
        visited[node] = true; // mark current cell as visited
        
        // travel through all children 
        for(int i = 0; i < graph[node].size(); i++){
            if(visited[graph[node][i].first] == false){ // if current one is not visited then call DFS for same
                if(DFS(graph,visited,graph[node][i].first,weight+graph[node][i].second)) //if there is an negative cycle then return true
                    return true;
            }else{
                // if current cell is visited and it forms a negative weight cycle then return true
                if(graph[node][i].second+weight < 0){
                    return true;
                }
            }
        }
        // this is directed graph so visited array will store true for the nodes which are present in the recursion stack
        // now i am going to return this fuction so i will mark false at this node
        visited[node] = false; 
        return false; // we haven't found any negative waight cycle
    }
    
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<vector<pair<int,int>>> graph(n); // to store graph
	    for(int i = 0; i < edges.size(); i++){
	        graph[edges[i][0]].push_back({edges[i][1],edges[i][2]}); // push pair of node,weight 
	    }
	    
	    vector<bool> visited(n); // to mark that current node is visited or not
	    for(int i = 0; i < n; i++){
	        // call DFS for every node
            if(DFS(graph,visited,i,0)) // if there is a cycle with negative weight then retuen 1
                return 1;
	    }
	    return 0; // at last return 0
	}
