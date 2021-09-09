// Problem Link : https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// DFS which will traverse astronaut of same country and find its number.
void DFS(vector<int> graph[], vector<bool>& visited, int node, int* size){
    visited[node] = true; // mark node as visited
    (*size)++; // update size at every node
    
    // call DFS to other unvisited children. 
    int n = graph[node].size();
    for(int i = 0; i < graph[node].size(); i++){
        if(visited[graph[node][i]] == false){
            DFS(graph, visited, graph[node][i], size);
        }
    }
}
long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> graph[n];
    int sz = astronaut.size();
    // create graph
    for(int i = 0; i < sz; i++){
        graph[astronaut[i][0]].push_back(astronaut[i][1]);
        graph[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    
    vector<bool> visited(n); // visited array 
    vector<int> comp; // to store number of astronauts in same country 
    // DFS
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            int size_of_comp = 0;
            DFS(graph, visited, i, &size_of_comp);
            comp.push_back(size_of_comp); // add number of astronaut of same country into comp 
        }
    }
    long long int ans = 0;
    int size_comp = comp.size();
    for(int i = 0; i < size_comp; i++){
        ans += comp[i]*(n-comp[i]); // i can make pair with any astronaut which is not in my country
    }
    return ans/2; // i had counted every pair 2 times 
}
