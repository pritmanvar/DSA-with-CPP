// Problem Link : https://codeforces.com/problemset/problem/118/E

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool DFS(vector<int> graph[], vector<bool>& visited, vector<int>& inTime, vector<int>& lowTime,vector<pair<int,int>>& ans, int node, int parent, int* timer){
    inTime[node] = lowTime[node] = *timer;
    visited[node] = true;
    (*timer)++;

    // traverse through adjacency list of node.
    for(int i = 0; i < graph[node].size(); i++){
        int child = graph[node][i];

        if(child == parent) continue;
        else if(visited[child] == true){ 
            if(inTime[node] < lowTime[child]){ // condition for bridge.
                return true;
            }
            lowTime[node] = min(lowTime[node],lowTime[child]); // update lowTime of current node.

            // if it is back-edge then this edge will be present in the directed graph.
            if(inTime[node] > inTime[child])
                ans.push_back({node,child});
        }else{
            if(DFS(graph,visited,inTime,lowTime,ans,child,node,timer)){
                return true;
            }
            if(inTime[node] < lowTime[child]){ // condition for bridge.
                return true;
            }
            lowTime[node] = min(lowTime[node],lowTime[child]); // update low time.

            // since this edge is a part of DFS this edge will be present in the directed graph.
            ans.push_back({node,child});
        }
    }
    return false;
}
int main() 
{
    int n,m;
    cin >> n >> m;

    vector<int> graph[n+1];
    vector<bool> visited(n+1,false);
    vector<int> inTime(n+1,-1), lowTime(n+1,-1);
    int timer = 1;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<pair<int,int>> ans;
    bool isValid = true;

    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            if(DFS(graph,visited,inTime,lowTime,ans,i,-1,&timer)){
                // there is a bridge in the graph so we can't give direction which follows rules to the graph.
                isValid = false;
                break;
            }
        }
    }

    if(isValid){ // if graph doesn't contain any bridge then print ans.
        for(auto i : ans){
            cout << i.first << " " << i.second << endl;
        }
    }else{
        cout << 0 << endl;
    }
    return 0;
}
