/* Problem Link : https://practice.geeksforgeeks.org/problems/level-order-traversal/1#
    
    A binary tree Node
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
        
        Node(int x){
            data = x;
            left = right = NULL;
        }
    };*/
    vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        queue<Node*> q;
        
        q.push(node); // add root into queue
        
        while(q.empty() == false){
            // taking node at front and adding that data into ans
            Node* temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            
            // adding children of that node into queue 
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        
        return ans;
    }
