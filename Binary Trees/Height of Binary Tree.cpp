/* Problem Link : https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#
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
    int height(struct Node* node){
        // I will traverse tree by level order and count number of levels 
        queue<Node*> q;
        q.push(node);
        
        int answer = 0;
        
        while(q.empty() == false){
            int count = q.size();
            
            for(int i = 0; i < count; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            answer++; // updating level
        }
        return answer;
    }
