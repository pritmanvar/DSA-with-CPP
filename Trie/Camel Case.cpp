// Problem Link : https://practice.geeksforgeeks.org/problems/camel-case04234120/1/?track=P100-Trie&batchId=197#
    
    // Structure to represent Trie.
    struct TrieNode{
        bool isend = false;
        unordered_map<char,TrieNode*> children;
        vector<pair<string,string>> words; // to store words corrospondinf to abbreviations.
    };
    
    // Function to insert a new word into trie.
    TrieNode* insert(TrieNode* trie, string key, string word){
        TrieNode* curr = trie;
        for(int i = 0; i < key.size(); i++){
            if(curr->children.count(key[i]) == 0){ // if current char is not present then insert new word.
                curr->children[key[i]] = new TrieNode();
            }
            curr = curr->children[key[i]];
            curr->words.push_back({key,word}); // insert word corrosponding to abbreviations into the words array.
            if(i == key.length()-1){
                curr->isend = true;
            }
        }
        return trie;
    }
    void findAllWords(vector<string> dict, string pattern) 
    {
        TrieNode* trie = new TrieNode();
        // insert every words into the trie.
        for(int i = 0; i < dict.size(); i++){
            // i will just insert its abbreviations.
            string cap = "";
            for(int j = 0; j < dict[i].length(); j++){
                if(dict[i][j] >= 'A' && dict[i][j] <= 'Z'){
                    cap += dict[i][j];
                }
            }
            trie = insert(trie,cap,dict[i]);
        }
        // search for the pattern in the trie and it we find that then print its words array else print No match found.
        TrieNode* curr = trie;
        for(int i = 0; i < pattern.size(); i++){
            if(curr->children.count(pattern[i]) == 0){
                    cout << "No match found";
                return;
            }
            curr = curr->children[pattern[i]];
            if(i == pattern.length()-1){
                sort(curr->words.begin(),curr->words.end());
                for(int j = 0; j < curr->words.size(); j++){
                    cout << curr->words[j].second << " ";
                }
            }
        }
    }
