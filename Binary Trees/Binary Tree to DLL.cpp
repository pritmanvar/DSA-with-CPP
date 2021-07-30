/* Problem Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
    
    Structure for tree and linked list
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
    Node* head = NULL; // it will be head of doubly linkedlist
    Node* curr = NULL; // it will be last node of doubly linkedlist
    
    void convert(Node* root){
        if(root == NULL) // base case
            return;
        
        convert(root->left); // calling for left subtree
        
        if(curr){ // making current node as node of linkedlist
            curr->right = root; // setting next pointer of last node
            root->left = curr; // setting previous pointer of current node
            curr = curr->right; // moving ahead
        }else{ // if current node is head
            head = root; 
            curr = root;
        }
        convert(root->right); // calling for right subtree
    }
    Node * bToDLL(Node *root)
    {
        convert(root);
        curr->right = NULL;
        
        return head;
    }
