// Problem Link : https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1#
    int mn; // to store minimum diameter
    // DFS
    void DFS(vector<vector<pair<int,int>>>& graph, vector<bool>& visited, int node, vector<vector<int>>& ans, int tank){
        visited[node] = true; // mark current node visited
        // if number of adjacent of current home is 0 then at this house tap should be installed
        // so add tank,tap and minimun diameter into ans
        if(graph[node].size() == 0){
            ans.push_back({tank,node,mn});
        }
        // traverse through adjancenty list of current house
        for(int i = 0; i < graph[node].size(); i++){
            mn = min(mn,graph[node][i].second); // update minimum diameter
            DFS(graph,visited,graph[node][i].first,ans,tank); // call dfs to adjacent house
        }
        visited[node] = false; // mark current node unvisited
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<pair<int,int>>> graph(n+1); // to store graph
        vector<vector<pair<int,int>>> transpos(n+1); // to store transpos graph
        vector<bool> available(n+1); // to check which house is present in the graph
        
        // create graph and transpos graph
        for(int i = 0; i < p; i++){
            available[a[i]] = available[b[i]] = true; // mark both houses as available
            graph[a[i]].push_back({b[i],d[i]});
            transpos[b[i]].push_back({a[i],d[i]});
        }
        vector<bool> visited(n+1); // to mark node as visited
        vector<vector<int>> ans; // to store answer
        
        // DFS
        for(int i = 1; i <= n; i++){
            // if in the transpos graph current node has not any adjacent house and it is present in the graph
            // then i will call DFS for current house
            if(transpos[i].size() == 0 && available[i]){
                mn = INT_MAX; // initilize minimum diameter as infinite
                DFS(graph,visited,i,ans,i);
            }
        }
        return ans;
    }
