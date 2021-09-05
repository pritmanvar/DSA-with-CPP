// Problem Link : https://practice.geeksforgeeks.org/problems/topological-sort/1#
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> answer; // to store topological sort.
	    vector<int> inDegree(V); // to store in degree of every node
	    
	    for(int i = 0; i < V; i++){
	        for(int j = 0; j < adj[i].size(); j++){
	            // there is an edge between i to adj[i][j] so i will increment in degree of adj[i][j] by onw
	            inDegree[adj[i][j]]++;
	        }
	    }
	    vector<bool> visited(V); // to store visited nodes
	    queue<int> q; // queue for topological sort
	    
	    // if indegree of node i is 0 then i will add that into queue
	    for(int i = 0; i < V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	            visited[i] = true;
	        }
	    }
	    while(q.size() != 0){
	        // get a nodw with 0 indegree and add that into answer
	        int temp = q.front(); 
	        answer.push_back(temp);
	        q.pop();
	        
	        // travelling through its adjacency list and reduce indegree of all by one
	        // because i had process one of them parent node
	        for(int i = 0; i < adj[temp].size(); i++){
	            inDegree[adj[temp][i]]--;
	            // if node is not visited and it has 0 indegree then i will add that into queue
	            if(visited[adj[temp][i]] == false && inDegree[adj[temp][i]] == 0){ 
	                q.push(adj[temp][i]);
	                visited[adj[temp][i]] = true;
	            }
	        }
	    }
	    return answer;
	}
