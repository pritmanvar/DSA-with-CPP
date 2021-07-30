/* Problem Link : https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#
    
    The structure of the binary tree is as follows
    struct Node
    {
        int data;
        Node* left;
        Node* right;
    };*/
    bool check(Node *root)
    {
        bool isleaf = false; // if we have visited any leaf then it will be true
        
        queue<Node*> q; // queue for level order traversal
        
        // Level order traversal
        q.push(root);
        while(q.empty() == false){
            int count = q.size();
            
            for(int i = 0; i < count; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left == NULL && temp->right == NULL){ // if current node is leaf then i will mark isleaf as true
                    isleaf = true;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            if(isleaf && q.size() > 0){ // if we have visited any leaf and there is more level in queue then i will return false
                return false;
            }
        }
        return true; // if all leaves are at same level then i will return true
    }
