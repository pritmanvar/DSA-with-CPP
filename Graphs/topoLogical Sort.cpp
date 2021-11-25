#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void topoLogicalSort(vector<int> graph[], vector<int>& inDegree, vector<int>&topoSort){
    queue<int> q;
    for(int i = 1; i < inDegree.size(); i++){
        if(inDegree[i] == 0) q.push(i); // if current node had inDegree 0 then it is ready to be inserted in topological sort vector
    }

    // BFS
    while (q.empty() == false){
        int curr = q.front();
        topoSort.push_back(curr);
        q.pop();

        for(int i = 0; i < graph[curr].size(); i++){
            inDegree[graph[curr][i]]--;
            if(inDegree[graph[curr][i]] == 0){
                q.push(graph[curr][i]);
            }
        }
    }
}
int main() 
{
    int n,m;
    cin >> n >> m;
    vector<int> graph[n+1];
    vector<int> inDegree(n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }
    vector<int> topoSort;
    topoLogicalSort(graph,inDegree,topoSort);
    if(topoSort.size() == n){
        cout << "Topo Logical Sort : ";
        for(int i = 0; i < n; i++){
            cout << topoSort[i] << " ";
        }
        cout << endl;
    }else{
        cout << "Topo Logical Sort is not possible.\n";
    }
    return 0;
}
