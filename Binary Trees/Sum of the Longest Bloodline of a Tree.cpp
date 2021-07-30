/* Problem Link : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#
    
    structure of the node of the binary tree is as
    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
    
        Node(int x)
        {
            data = x;
            left = NULL;
            right = NULL;
        }
    };*/
    int max_height = 0; // to store max height till now
    int max_sum = 0; // to store max sum of max height
    void solve(Node* root, int height, int sum){
        if(root == NULL) // Base case
            return;
        
        // if it is height of current node is greater then max_height then i will update max_height and sum if possible
        if(height >= max_height){
            max_height = height;
            max_sum = max(max_sum,sum+root->data);
        }
        // calling for left and right subtree
        solve(root->left, height+1,sum+root->data);
        solve(root->right, height+1,sum+root->data);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        solve(root,0,0);
        return max_sum; // returning answer
    }
