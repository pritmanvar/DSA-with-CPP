/* Problem Link : https://leetcode.com/problems/clone-graph/
    
    Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
         val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };*/
    Node* cloneGraph(Node* node) {
        if(node == NULL) // base case
            return NULL;
        
        queue<pair<Node*,Node*>> q; // queue for BFS
        unordered_map<Node*,Node*> visited; // visited map
        
        Node* newGraph = new Node(node->val); // cloning the first node
        
        // BFS
        visited[node] = newGraph; 
        q.push({node,newGraph});         
        while(q.empty() == false){
            int count = q.size();
            for(int i = 0; i < count; i++){
                pair<Node*,Node*> temp = q.front();
                q.pop();
                
                // will traverse through all the neighbors of temp.first node
                for(int j = 0; j < temp.first->neighbors.size(); j++){
                    Node* curr = temp.first->neighbors[j];
                    
                    // if current node is not visited then i will create new node with same value and create an edge in my newGraph
                    if(visited.count(curr) == 0){
                        Node* child = new Node(curr->val);
                        visited[curr] = child;
                        temp.second->neighbors.push_back(child);
                        q.push({curr,child});
                    }else{ // if current node is visited then i will only create an edge
                        temp.second->neighbors.push_back(visited[curr]);
                    }
                }
            }
        }
        return newGraph; // return cloned graph
    }
