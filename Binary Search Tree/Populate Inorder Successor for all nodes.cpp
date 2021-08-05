/* Problem Link : https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#
    
    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
        struct Node *next;
    
        Node(int x)
        {
            data = x;
            left = NULL;
            right = NULL;
            next = NULL;
        }
    };*/
    void populateNext(Node *root)
    {
        // I will add every Node into map
        map<int,Node*> mp;
        
        // to add node into map i will do level order traversal
        queue<Node*> q; // queue for level order traversal
        
        // levell order traversal
        q.push(root);
        while(q.size() > 0){
            int count = q.size();
            for(int i = 0; i < count; i++){
                Node* temp = q.front();
                q.pop();
                
                mp[temp->data] = temp; // adding current node into map
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        // now i will traverse map from reverse
        // here map is sorter so successor for ith node in map will be (i+1)th node
        // so i will maintain current node for next iterator
        // successor for largest node will be -1 so initilizing succ as NULL
        Node* succ = NULL;
        for(auto i = mp.rbegin(); i != mp.rend(); i++){
            i->second->next = succ; // pointing next of current Node to it's successior
            succ = i->second; // updating succ for its previous Node
        }
    }
