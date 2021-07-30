/* Problem Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#
    
    A binary tree node
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
    vector<Node*> path_for_n1; // it will store path from root to n1
    vector<Node*> path_for_n2; // it will store path from root to n2
    
    void NodeToRootPath(Node* root, vector<Node*> path, int n1, int n2){
        if(root == NULL) // base case
            return;
        
        path.push_back(root); // adding root into current path
        // if current node is equal to n1 then set current path at path_for_n1
        if(root->data == n1){
            path_for_n1 = path;
        }
        // if current node is equal to n2 then set current path at path_for_n2
        if(root->data == n2){
            path_for_n2 = path;
        }
        
        // calling for left and right subtree
        NodeToRootPath(root->left, path, n1, n2);
        NodeToRootPath(root->right, path, n1, n2);
        
        // removing current node from path because i am leaving it
        path.pop_back();
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        // clearing both vectors at starting of code
        path_for_n1.clear();
        path_for_n2.clear();
        
        // calling function to fill both vectors
        vector<Node*> path;
        NodeToRootPath(root, path, n1, n2);
        
        Node* ans = NULL;
        
        for(int i = 0; i < min(path_for_n1.size(),path_for_n2.size()); i++){
            // if node of both path are diffrent then break the loop
            if(path_for_n1[i]->data != path_for_n2[i]->data){
                break;
            }
            
            // this loop will run till last same node so ans will contain lowest common node
            ans = path_for_n1[i];
        }
        return ans;
    }
