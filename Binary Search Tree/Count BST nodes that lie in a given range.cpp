// Problem Link : https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#
int ans = 0; // to store answer
void solve(Node* root, int l, int h){
    if(root == NULL) // base case
        return;
    
    if(root->data < l){ // if current data is less then lower limit then i will call for right subtree
        solve(root->right,l,h);
    }else if(root->data > h){ // if current data is greater then upper limit then i will call for left subtree
        solve(root->left,l,h);
    }else{ // if data is in the range then i will update answer and call for left and right subtree
        ans++;
        solve(root->left,l,h);
        solve(root->right,l,h);
    }
}
int getCount(Node *root, int l, int h)
{
    ans = 0; // reseting answer
    solve(root, l, h); // call for solve function
    return ans;
}
