/* Problem Link : https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
    
    Complete the function below
    Node is as follows:
    struct Node {
        int data;
        Node *left;
        Node *right;
    
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };*/
    bool isIsomorphic(Node *root1,Node *root2)
    {
        // If both trees are NULL then i will return true
        if(root1 == NULL && root2 == NULL){ 
            return true;
        }
        // If any one tree is NULL and another is not NULL then i will return false because it can't be an isomorpic tree
        if(!(root1 && root2)){
            return false;
        }
        
        // if data of both root is not same then it can't be an isomorphic tree so return false
        if(root1->data != root2->data)
            return false;
        
        // we have 2 choices
        // 1. we will not swap left and right subtrees
        // 2. we will swap left and right subtrees
        bool ans1 = isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
        bool ans2 = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
        
        return ans1 || ans2; // if any of these returns true then i will return true
    }
