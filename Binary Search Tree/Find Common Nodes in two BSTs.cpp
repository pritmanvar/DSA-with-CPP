// Problem Link : https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/?track=P100-Binary%20Search%20Tree#
    unordered_set<int> st;
    vector<int> ans;
    // to do tree traversal 
    void traverse(Node* root){
        if(root == NULL)
            return;
        if(st.count(root->data) == 1){ // if it is already present in the set then it is common node
            ans.push_back(root->data);
        }else{ // else add this in the set
            st.insert(root->data);
        }
        // traversal for left and right subtree
        traverse(root->left);
        traverse(root->right);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        st.clear();
        ans.clear();
        
        // traversal for both trees
        traverse(root1);
        traverse(root2);
        // sort answer
        sort(ans.begin(),ans.end());
        return ans;
    }
