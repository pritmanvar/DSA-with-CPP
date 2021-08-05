/* Problem Link : https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1#

Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};*/

// i will add every subtree into a unordered_map in form of string 
// while inserting i will check that this subtree is present in that or not
unordered_map<string,int> subtrees; // unordered_map to store subtrees
vector<Node*>ans; // answer

// this function will update ans and return string formation of given tree
string treeToString(Node* root){
    if(root == NULL) // base case. here i am using 'N' to represent NULL
        return "N";
    
    // to store left and right subtree
	string left = "";
	string right = "";
		
    left = treeToString(root->left); // it will convert left subtree into string
 	right = treeToString(root->right); // it will convert right subtree into string
    
    string current = left + to_string(root->data) + right; // converting current subtree into string
    

    if(subtrees.count(current) == 1){ // if current subtree is present then i will try to update ans
        if(subtrees[current] == 1) // if frequency of current subtree is one then i will add it in ans if it is more then one then it will add when i had seen this subtree 2nd time
            ans.push_back(root);
    }
    subtrees[current]++; // update frequency of current subtree

    return current; // returning current subtree
}
vector<Node*> printAllDups(Node* root)
{
    // reseting global variabls
    subtrees.clear();
    ans.clear();
    
    // calling function
    treeToString(root);
    
    return ans; // returning answer
}
