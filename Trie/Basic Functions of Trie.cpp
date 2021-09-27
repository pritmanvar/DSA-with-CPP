#include<bits/stdc++.h>

using namespace std;

// structure to represent trie.
struct Trie{
    bool isend;
    unordered_map<char,Trie*> child;

    Trie(bool end){
        child.clear();
        isend = end;
    }
};

// function to insert new word into the trie.
Trie* insert(Trie* trie, string word){
    Trie* curr = trie;

    for(int i = 0; i < word.length(); i++){
        if(curr->child.count(word[i]) == 0){ // if current char is not present then i will create new one
            if(i != word.length()-1)
                curr->child[word[i]] = new Trie(false);
            else // if it is end of word then its isend will be true.
                curr->child[word[i]] = new Trie(true);
        }
        curr = curr->child[word[i]]; // move to next char
    } 
    return trie;
}

// function to search a word into the trie
bool search(Trie* trie, string word){
    Trie* curr = trie;

    for(int i = 0; i < word.length(); i++){
        if(curr->child.count(word[i]) == 0){ // if current char is not present then word is not present into trie.
            return false;
        }
        curr = curr->child[word[i]]; // move to next char
    }
    return curr->isend; // if isedd of last char is true then word is present else it is not present in the trie
}

// to delete a word from trie.
Trie* remove(Trie* trie, string word, int indx){
    if(indx == word.length()){ // if current node is last node then make its isend as false.
        trie->isend = false;
        if(trie->child.size() == 0){ // if there isn't any char after this then i can delete this one.
            delete(trie);
            return NULL;
        }
        return trie;
    }

    // calling for remove function recursively to next char.
    if(trie->child.count(word[indx]) == true){
        trie->child[word[indx]] = remove(trie->child[word[indx]],word,indx+1);
    }
    // if current its node is deleted then i will erase same from child map of current one too.
    if(trie->child[word[indx]] == NULL){
        trie->child.erase(word[indx]);
    }
    // if there isn't any char in the child of current node and it is not end of any other word then i can delete this one too.
    if(trie->child.size() == 0 && trie->isend == false){
        delete(trie);
        return NULL;
    }
    return trie;
}
int main() 
{
    Trie* trie = new Trie(true);


    int n;
    cout << "Enter the number of words to be inserted\n";
    cin >> n;

    string str;
    for(int i = 0; i < n; i++){
        cout << "Enter the word to be inserted\n";
        cin >> str;

        trie = insert(trie,str);
    }

    cout << "Enter the word which you want to search\n";
    cin >> str;
    cout << search(trie,str) << endl;

    cout << "Enter the word which you want to delete\n";
    cin >> str;
    trie = remove(trie,str,0);

    cout << "calling search after deletion\n";
    cout << search(trie,str) << endl;

    return 0;
}
