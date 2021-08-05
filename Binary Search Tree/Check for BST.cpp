    // Problem Link : https://practice.geeksforgeeks.org/problems/check-for-bst/1#
    
    // I will solve this with help of range 
    // initially range of root will be -inf to +inf
    // now if i call it's left then range of this root must be -inf to data of it's parent
    // ans if i call it's right then range of this root must be data of it's parent to +inf
    bool check(Node* root, int min, int max){
        if(root == NULL) // base case
            return true;
        
        // it current root is in range then i will call for its left and right root and return that's result
        if(root->data > min && root->data < max){
            return check(root->left,min,root->data)&&check(root->right,root->data,max);
        }
        // if current root is out of range then i will return false
        return false;
    }
    bool isBST(Node* root){
        // calling for check function
        return check(root, INT_MIN, INT_MAX);
    }
