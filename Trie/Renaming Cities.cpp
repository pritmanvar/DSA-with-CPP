// Problem Link : https://practice.geeksforgeeks.org/problems/renaming-cities28581833/1/?track=P100-Trie&batchId=197#
    
    // structure to represent TrieNode.
    struct TrieNode{
        TrieNode* children[26];
        bool isend = false;
    };
    
    // function to get code corresponding to string str.
    void getcode(TrieNode* trie, string str, int count){
        TrieNode* curr = trie; // to traverse trie.
        
        string ans = ""; // to store answer.
        bool get = false; // to mark that we got our answer or not.
        
        // traverse through string length.
        for(int i = 0; i < str.length(); i++){
            // if current char is not present in the child array of current trienode then it is possibal answer
            if(curr->children[str[i]-'a'] == NULL){
                // if we haven't get our answer then i will update ans.
                if(get == false)
                    ans += str[i];
                curr->children[str[i]-'a'] = new TrieNode(); // create new TrieNode and add that into trie.
                // here we got our answer so i will mark get as true.
                get = true; 
            }
            // if it is last char of the string.
            if(i == str.length()-1){
                if(get == false){ // if we haven't get our answer the i will add current char into answer
                    ans += str[i];
                    if(count > 0) // if current string is appeared more than 0 times ago then i will add that number after the code.
                    ans += + " " + to_string(count+1);
                }
                // here we got our answer so i will mark get as true.
                get = true;
                curr->children[str[i]-'a']->isend = true; // mark current char as end of word.
            } 
            curr = curr->children[str[i]-'a']; // move to next node.
            // it i haven't get answer then add current char into the answer.
            if(get == false)
                ans += str[i];
        }
        // print answer.
        cout << ans << endl;
    }
    void check(string *arr, int n){
        TrieNode* trie = new TrieNode(); // initilize new trie.
        
        // unorder map to count frequency of every string
        unordered_map<string,int> mp;
        for(int i = 0; i < n; i++){
            // call getcode function for every string ans increment its frequency.
            getcode(trie,arr[i],mp[arr[i]]);
            mp[arr[i]]++;
        }
    }
