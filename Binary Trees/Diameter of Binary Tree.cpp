/* Problem Link : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
    
    Tree node structure  used in the program
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
    
        Node(int x){
            data = x;
            left = right = NULL;
        }
    }; */
    int dm = 0; // In this variable we will store diameter of tree
    // function to find height of tree
    // with help of height we will find diameter of tree
    int height(Node* root){
        // Base case
        if(root == NULL)
            return 0;
        
        // finding height of left and right subtree
        int height_left = height(root->left);
        int height_right = height(root->right);
        
        // diameter can be previous diameter or sum of height of left subtree or right subtree +1
        dm = max(dm,height_left+height_right+1);
        
        // returning height because it is need for parent to find their diameter
        return 1+max(height_left,height_right);
    }
    int diameter(Node* root) {
        // initilize diameter as 0
        dm = 0; 
        
        height(root);
        
        return dm;
    }
