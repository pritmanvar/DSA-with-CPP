/* Problem Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#
    
    The Node structure is
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
    // i will traver binary tree and insert that node into BST
    // function to insert node
    Node* insert(Node* root, int data){
        if(root == NULL) // if root is NULL then i will return new nodw
            return new Node(data);
        
        Node* store = root; // to store root
        Node* pre = NULL; // to store parent of current root
        
        // finding position for new node
        while(root){
            pre = root;
            if(root->data < data){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        // adding new node
        if(pre->data < data)
            pre->right = new Node(data);
        else
            pre->left = new Node(data);
        // return root of tree
        return store;
    }
    Node *binaryTreeToBST (Node *root)
    {
        Node* new_root = NULL; // root of BST
        
        // queue for level order traversaal
        queue<Node*> q;
        
        // level order traversal
        q.push(root);
        while(q.empty() == false){
            int count = q.size();
            
            for(int i = 0; i < count; i++){
                Node* temp = q.front();
                q.pop();
                
                new_root = insert(new_root,temp->data); // inserting root in BST
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return new_root; // return root of BST
    }
