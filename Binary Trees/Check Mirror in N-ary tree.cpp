// Problem Link : https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1
    // Structure for Node
    struct Node{
        int data;
        Node* left;
        Node* right;
        
        Node(int x){
            data = x;
            left = right = NULL;
        }
    };
    // it will travel a map in pre order
    void preorder(Node* root, vector<int>& ans){
        if(root == NULL)
            return;
        
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // If both tree are mirror of each other then
        // traversal in which first we visit left subtree and another traversal in which first we visit right subtree will be same
        
        unordered_map<int,Node*> mp1; // 1st map for tree from A
        unordered_map<int,Node*> mp2; // 2nd map for tree from B
        
        // setting root of both tree
        Node* root1 = new Node(A[0]);
        Node* root2 = new Node(B[0]);
        
        // adding roots into map
        mp1[A[0]] = root1;
        mp2[B[0]] = root2;
        
        // constructing trees
        for(int i = 0; i < 2*e; i += 2){
            if(mp1[A[i]]->left == NULL){ // in 1st tree i will try to set left node first 
                Node* temp = new Node(A[i+1]); // creating new node
                mp1[A[i]]->left = temp; // setting left node
                mp1[A[i+1]] = temp; // adding new node to map
            }else{
                // same as upper one
                Node* temp = new Node(A[i+1]);
                mp1[A[i]]->right = temp;
                mp1[A[i+1]] = temp;
            }
            
            // making 2nd tree same as 1st one but here 1st i will try to set right subtree 
            if(mp2[B[i]]->right == NULL){
                Node* temp = new Node(B[i+1]);
                mp2[B[i]]->right = temp;
                mp2[B[i+1]] = temp;
            }else{
                Node* temp = new Node(B[i+1]);
                mp2[B[i]]->left = temp;
                mp2[B[i+1]] = temp;
            }
        }
        // calling for pre-order traversal for tree1
        vector<int> ans1;
        preorder(root1,ans1);
        // calling for pre-order traversal for tree2
        vector<int> ans2;
        preorder(root2,ans2);
        
        return ans1 == ans2; // if both are same then return 1
    }
