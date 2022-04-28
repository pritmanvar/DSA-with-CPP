// Problem Link : https://leetcode.com/problems/smallest-string-with-swaps/

// We can sort each connected component alone to get the lexicographically minimum string.
class Solution {
private:
    // sort indivudial component using count sort
    void sortComp(string& s, vector<int>& comp){
        int freq[26] = {0};
        for(int i = 0; i < comp.size(); i++){
            freq[s[comp[i]]-'a']++;
        }
        int indx = 0;
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                s[comp[indx]] = 'a'+i;
                freq[i]--;
                indx++;
            }
        }
    }
    // DFS to find connected component
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& comp, int node){
        if(visited[node] == true)
            return;
        visited[node] = true;
        comp.push_back(node);
        
        for(int i = 0; i < graph[node].size(); i++){
            dfs(graph, visited, comp, graph[node][i]);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> graph(s.length());
        vector<bool> visited(s.length());
        
        for(int i = 0; i < pairs.size(); i++){
            if(pairs[i][0] > pairs[i][1])
                swap(pairs[i][0],pairs[i][1]);
        }
        sort(pairs.begin(),pairs.end());
        pairs.erase(unique(pairs.begin(),pairs.end()),pairs.end()); // remove same pairs
        
        for(int i = 0; i < pairs.size(); i++){ // create graph
            graph[pairs[i][0]].push_back(pairs[i][1]);
            graph[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i = 0; i < s.length(); i++){ // call dfs for components
            vector<int> comp;
            dfs(graph, visited, comp, i);
            sort(comp.begin(),comp.end()); // to get index in sorted order
            sortComp(s,comp); // sort component
        }
        return s;
    }
};
