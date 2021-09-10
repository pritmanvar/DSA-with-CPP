// Problem Link : https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/?track=P100-Binary%20Search%20Tree#
    int minDiff(Node *root, int k)
    {
        int ans = INT_MAX; // initialize answer as infinity 
        // i will try to find root.
        while(root != NULL){
            ans = min(ans,abs(k-root->data)); // update ans as minimum difference till now
            // it data of the root is same as given integer then my answer will be 0
            if(root->data == k)
                return 0;
            // go left side if current data is larger else go to the right side
            if(root->data > k)
                root = root->left;
            else
                root = root->right;
        }
        return ans;
    }
