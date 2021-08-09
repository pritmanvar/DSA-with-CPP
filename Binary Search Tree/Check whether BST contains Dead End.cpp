/* Problem Link : https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

// In BST we add new node at leaves
// i will find range for that leaves and check that i can add any node or not
// if not then i will mark my answer as true
bool ans = false;
void check(Node* root, int l, int h){
    if(root == NULL){ // base case
        return;
    }
    
    if(root->left == NULL && root->right == NULL){ 
        if(l >= root->data && h <= root->data){ // if current node is leaf then i will check that can i add any node after it or not with help of range and mark ans
            ans = true;
        }
    }
    // calling for left and right subtree
    check(root->left, l, root->data-1);
    check(root->right, root->data+1, h);
}
bool isDeadEnd(Node *root)
{
    ans = false; // reset the answer
    check(root, 1, INT_MAX);
    return ans;
}
