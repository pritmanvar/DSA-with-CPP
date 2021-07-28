/* Problem Link : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

A binary tree node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
bool ans = true; // when sub tree is not balanced then i will mark it false
int height(Node* root){
    if(root == NULL)
        return 0;
        
    // find height of both sub tree
    int lh = height(root->left);
    int rh = height(root->right);
    
    // if any subtree is not balanced then i will return -1 from here
    if(lh == -1 || rh == -1)
        return -1;
    
    // if current tree is not balanced then mark ans as false and return -1
    if(abs(lh-rh) > 1){
        ans = false;
        return -1;
    }
    // else return -1
    return 1+max(lh,rh);
}
bool isBalanced(Node *root)
{
    ans = true;
    height(root); // calling for function
    return ans;
}
