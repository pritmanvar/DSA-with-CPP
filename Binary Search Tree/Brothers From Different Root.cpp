/* Problem Link : https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1#
    
    Structure of the Node of the BST is as
    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
    
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };*/
    // will do inorder traversal of tree and store that in vector
    void inOrder(Node* root, vector<int>& tree){
        if(root == NULL)
            return;
        
        inOrder(root->left, tree);
            tree.push_back(root->data);
        inOrder(root->right, tree);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        // vectors to store inorder traversals of both trees
        vector<int> tree1;
        vector<int> tree2;
        
        // inorder traversal for both trees
        inOrder(root1,tree1);
        inOrder(root2,tree2);
        
        int pairs = 0;
        
        // two pointer approch to find number of pairs
        int i = 0;
        int j = tree2.size()-1;
        while(i < tree1.size() && j >= 0){
            if(tree1[i] + tree2[j] == x){
                pairs++;
                i++;
                j--;
            }else if(tree1[i] + tree2[j] < x){
                i++;
            }else{
                j--;
            }
        }
        return pairs;
    }
