// Problem Link : https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/?track=P100-Binary%20Search%20Tree&batchId=197#
    
    // inorder traversal to get sorted order of tree.
    void inorder(Node* root, vector<int>& in){
        if(root == NULL)
            return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        // get sorted order of both tree.
        vector<int> in1;
        inorder(root1,in1);
        vector<int> in2;
        inorder(root2,in2);
        
        // merge them using 2 pointer algo.
        vector<int> ans;
        int i = 0, j = 0;
        while(i < in1.size() && j < in2.size()){
            if(in1[i] < in2[j]){
                ans.push_back(in1[i]);
                i++;
            }else{
                ans.push_back(in2[j]);
                j++;
            }
        }
        ans.insert(ans.end(),in1.begin()+i,in1.end());
        ans.insert(ans.end(),in2.begin()+j,in2.end());
        
        return ans;
    }
