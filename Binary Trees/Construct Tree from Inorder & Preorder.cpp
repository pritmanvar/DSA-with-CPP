/* Problem Link : https://practice.geeksforgeeks.org/problems/construct-tree-1/1#
    
    Complete the code here.
    Node is as follows:
    struct Node
    {
      int data;
      Node* left;
      Node* right;
    };*/
    int indx = 0;
    Node* build(int in[], int st, int ed, int pre[], int n){
        
        if(st > ed || indx == n) // if st is greater then ed then its parenet node must be leaf
            return NULL;
            
        int i;
        // i will search node at pre[indx] in inorder
        for(i = st; i <= ed; i++){
            if(in[i] == pre[indx]) // ith node is required node
                break;
        }
        Node* root = new Node(pre[indx]); // making new node
        indx++; // updationg indx
        
        root->left = build(in,st,i-1,pre, n); // in inorder element from st to i-1 will be elements of left subtree
        root->right = build(in,i+1,ed,pre, n); // in inorder element from i+1 to ed will be elements of right subtree
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        return build(in,0,n-1,pre, n);
    }
