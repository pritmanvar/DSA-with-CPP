/* Problem Link : https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#
    
    Structure of node
    struct Node {
        int data;
        Node *left;
        Node *right;
    
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };*/
    // I will do level order traversal and while that i will check that current node follows heap property or not
    bool isHeap(struct Node * tree)
    {
        queue<Node*> q; // queue for level order traversal
        bool null = false; // if we have seen any NULL node then this will true
        
        // tree traversal
        q.push(tree);
        while(q.size() != 0){
            int count = q.size();
            for(int i = 0; i < count; i++){
                Node* temp = q.front();
                q.pop();
                
                // these 2 if statment will check that data of current node is larger than its children or not
                // if not then it will return false
                if(temp != NULL && temp->left != NULL && temp->left->data > temp->data)
                    return false;
                if(temp != NULL && temp->right != NULL && temp->right->data > temp->data)
                    return false;
                
                // if there is any node who is not null after see a NULL node then it will brack complete tree property 
                // so return false
                if(null == true && temp != NULL)
                    return false;
                // if current node is NULL then make null true 
                if(temp == NULL)
                    null = true;
                
                // adding its left and right child into queue
                if(temp){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        // at last return true
        return true;
    }
