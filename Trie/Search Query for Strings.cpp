// Problem Link : https://practice.geeksforgeeks.org/problems/search-query-for-strings5049/1/?track=P100-Trie&batchId=197#

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    TrieNode* curr = root;
    
    for(int i = 0; i < key.length(); i++){
        if(curr->children[key[i]-'a'] == NULL){ // if current char is not present then i will add that
            curr->children[key[i]-'a'] = new TrieNode();
        }
        curr = curr->children[key[i]-'a']; // move to next char
        if(i == key.length()-1){ // if it is the end of word then its isEndOfWord will be true
            curr->isEndOfWord = true;
        }
    }
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode* curr = root;
    for(int i = 0; i < key.length(); i++){
        if(curr->children[key[i]-'a'] == NULL) // if current char is not present then key is not present
            return false;
        curr = curr->children[key[i]-'a']; // move to next char
    }
    return curr->isEndOfWord; // if isEndOfWord is the true then and only then current key is present
}

