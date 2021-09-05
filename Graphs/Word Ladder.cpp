// Problem Link : https://leetcode.com/problems/word-ladder/
    // Structure to represent a Node of Graph
    struct Node{
        string str;
        unordered_set<Node*> list; 
        
        Node(string val){
            str = val;
            list.clear();
        }
    };
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        bool contain = false;
        unordered_map<string,Node*> mp; // map to store node corrosponding to string
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == beginWord){
                contain = true;
                break;
            }
        }
        if(contain == false){ // if wordList doen't contain beginWord then i will add that
            wordList.push_back(beginWord);
        }
        
        Node* graph = new Node(wordList[0]);
        mp[wordList[0]] = graph;
        int n = wordList.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int diff = 0; 
                for(int k = 0; k < wordList[i].length(); k++){
                    if(wordList[i][k] != wordList[j][k])
                        diff++;
                }
                // if both string differs by a single letter then i will connect both in graph
                if(diff == 1){
                    Node* node1;
                    Node* node2;
                    // if node for ith and jth string is present in string then i will take from there else create new
                    if(mp.count(wordList[i]) == 1){
                        node1 = mp[wordList[i]];
                    }else{
                        node1 = new Node(wordList[i]);
                        mp[wordList[i]] = node1;
                    }
                    if(mp.count(wordList[j]) == 1){
                        node2 = mp[wordList[j]];
                    }else{
                        node2 = new Node(wordList[j]);
                        mp[wordList[j]] = node2;
                    }
                    // create edge between both nodes
                    node1->list.insert(node2);
                    node2->list.insert(node1);
                }
            }
        }
        graph = mp[beginWord]; // geting node of beginWord
        
        unordered_set<Node*> visited; // set to store visited nodes
        queue<Node*> q;
        
        // BFS
        q.push(graph);
        visited.insert(graph);
        int ans = 1;
        while(q.empty() == false){
            int count = q.size(); 
            ans++;
            for(int i = 0; i < count; i++){
                Node* temp = q.front();
                q.pop();
                
                for(auto node : temp->list){
                    if(node == mp[endWord]){ // if current node is endWord then return answer
                        return ans;
                    }
                    if(visited.count(node) == 0){
                        q.push(node);
                        visited.insert(node);
                    }
                }
            }
        }
        return 0;
    }
