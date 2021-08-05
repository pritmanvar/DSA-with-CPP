// Problem Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#
Node* LCA(Node *root, int n1, int n2)
{
    Node* lca = NULL;
    // i will travel till both required node are in left subtree or both are in right subtree
    // as i will find one or both are i different direction i will break the loop and return lcs
    while(root != NULL){
        lca = root;
        
        if(root->data < n1 && root->data < n2)
            root = root->right;
        else if(root->data > n1 && root->data > n2)
            root = root->left;
        else
            break;
    }
    return lca;
}
