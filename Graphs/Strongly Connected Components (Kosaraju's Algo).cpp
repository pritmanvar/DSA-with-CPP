// Problem Link : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
	void set_outTime(vector<int> adj[], vector<int>& outTime, vector<bool>& visited, int node){
	    visited[node] = true; // mark current node as visited
	    for(int i = 0; i < adj[node].size(); i++){ // traverse through all adjacency nodes
            if(visited[adj[node][i]] == false) // if current one is not visited then call same function for that
	            set_outTime(adj, outTime, visited, adj[node][i]);
	    }
	    // while returning push current node into outTime
	    // so at last this vector will store all nodes accordingly their out time
	    outTime.push_back(node); 
	}
	// DFS
	void DFS(vector<int> transpos[], int node, vector<bool>& visited){
	    visited[node] = true;
	    for(int i = 0; i < transpos[node].size(); i++){
            if(visited[transpos[node][i]] == false)
	            DFS(transpos, transpos[node][i], visited);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        // create transpos matrix
        // for example if there is a edge from a to b then in transpos matrix there will be edge from b to a
        vector<int> transpos[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                transpos[adj[i][j]].push_back(i);
            }
        }
        
        vector<int> outTime;
        vector<bool> visited(V);
        
        // fill outTime vector
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                set_outTime(adj, outTime, visited, i);
            }
        }
        fill(visited.begin(), visited.end(), false); // reset visited vector by false
        int ans = 0;
        
        // call DFS accordingly larger outtime
        for(int i = outTime.size()-1; i >= 0; i--){
            if(visited[outTime[i]] == false){
                ans++; // update ans
                DFS(transpos,outTime[i],visited);
            }
        }
        return ans; // return answer
    }
