/* Problem Link : https://practice.geeksforgeeks.org/problems/sum-tree/1#
    
    Tree node
    struct Node
    {
        int data;
        Node* left, * right;
    }; */
    bool ans = true;
    int check(Node* node){
        if(node == NULL){ // base case
            return 0;
        }
        if(ans == false) // if anyof subtree is not sum tree then return
            return 0;
        
        int sum = check(node->left); // finding sum of left subtree
        sum += check(node->right); // finding sum of right subtree
        
        // check that current subtree is sum tree or not if not then mark ans as false and return
        if(sum != node->data && (node->left != NULL || node->right != NULL)){
            ans = false;
            return 0;
        }
        return sum+node->data; // return sum for the parent 
    }
    bool isSumTree(Node* root)
    {
        ans = true;
        check(root); // calling check function
        return ans; 
    }
