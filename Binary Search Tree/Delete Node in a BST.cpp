// Problem Link : https://leetcode.com/problems/delete-node-in-a-bst/
    
    // this function will give new root after deleting a root
    // new root will be smallest root in the right subtree
    // because all other nodes in right subtree will be larger than it and since it is in right subtree so all nodes in left subtree will be smaller than it
    TreeNode* get_new_root(TreeNode* root){
        TreeNode* curr = root->right;
        while(curr != NULL && curr->left != NULL)
            curr = curr->left;
        
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int x) {
        if(root == NULL) // if root is null then nothing to delete so return root as it is
            return NULL;
    
        if(root->val < x){ // if val of current node is smaller then required node should be on the right side
            root->right = deleteNode(root->right,x); // setting modified subtree at right
        }else if(root->val > x){ // if val of current node is larger then required node should be on the left side
            root->left = deleteNode(root->left,x); // setting modified subtree at left
        }else{ // if current node is same as required node
            if(root->left == NULL){ // if left subtree is NULL then simplly i will deleteNode crurrent node and return its right node as root of modified subtree
                TreeNode* temp = root->right;
                return root->right;
            }else if(root->right == NULL){ // if right subtree is NULL then simplly i will deleteNode crurrent node and return its left node as root of modified subtree
                TreeNode* temp = root->left;
                return root->left;
            }else{ // if both subtree is not NULL
                TreeNode* temp = get_new_root(root); // getting new root
                root->val = temp->val; // changing value of current root to new root
                root->right = deleteNode(root->right,temp->val); // removing new root from right subtree because new root is from right subtree 
            }
        }
        return root;
    }
