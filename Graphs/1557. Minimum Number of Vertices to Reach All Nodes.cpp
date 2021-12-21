// Problem Link : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

/****************Approch**********************
1. if current node has 0 incoming edge then we can't reach from anywhere else
    so we must include current node into our answer.
2. if current node has some incoming edge then it can be reached from somewhere else
    so there it no need to include this into the answer.
    
In short we just have to count nodes with 0 incoming edges.
*/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incoming_edge(n);
        
        int size = edges.size();
        for(int i = 0; i < size; i++){
            incoming_edge[edges[i][1]] = true; // current node has incoming edge.
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(incoming_edge[i] == false)
                ans.push_back(i);
        }
        return ans;
    }
};
