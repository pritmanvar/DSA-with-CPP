/* Problem Link : https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
    
    The structure of the Binary Tree Node  is
    struct Node
    {
      char data;
      struct Node* left;
      struct Node* right;
    };*/
    
    // i will add every subtree into a set in form of string 
    // while inserting i will check that this subtree is present in that or not
    unordered_set<string> subtrees; // unorderedset to store subtrees
    int ans = 0; // answer
    
    // this function will update ans and return string formation of given tree
    string treeToString(Node* root){
        if(ans == 1) // if i had founded any duplicate subtree then there is no need to move farther so i will return empty string
            return "";
        if(root == NULL) // base case. here i am using 'N' to represent NULL
            return "N";
        
		string left = "";
		string right = "";
		
        left = treeToString(root->left); // it will convert left subtree into string
		if(left != "") // this is for optimization. if i had founded duplicate subtree then i will not call for right subtree
        	right = treeToString(root->right); // it will convert right subtree into string
        
        string current = left + to_string(root->data) + right; // converting current subtree into string
        
        // if number of nodes in subtree is greater or equal to two then i will try to insert current string into set
        if(root->left != NULL || root->right != NULL){
            if(subtrees.count(current) == 1){ // if current subtree is present then mark ans as 1 and return empty string
                ans = 1;
                return "";
            }else{
                subtrees.insert(current); // inserting current subtree into set
            }
        }

        return current; // returning current subtree
    }
    int dupSub(Node *root) {
        // reseting global variables
        ans = 0;
        subtrees.clear();
        
        // calling for function
        treeToString(root);
        
        return ans; 
    }
