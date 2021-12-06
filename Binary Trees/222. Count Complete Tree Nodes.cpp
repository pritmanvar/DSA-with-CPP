// Problem Link : https://leetcode.com/problems/count-complete-tree-nodes/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/


/***********************************************Approch***********************************************************
    1. get height of tree. (since it is complete Binary Tree hight of left most leaf will be height of tree.)
    2. First go to 1 step right and then go to left while you did't reach to height of tree.
        a. if there is a node then we can skip all nodes in the left of current path
        b. if there is NULL then we can skip all nodes in the right of current path.
    3. follow same algo for the subtrees which are not skipped.
*/
class Solution {
public:
    // get height of tree.
    int getLevel(TreeNode* root){
        if(root == NULL)
            return 0;
        return getLevel(root->left)+1;
    }
    
	// dir is the directin which indicates in which direction i have to move next.
	
	// Using val which will store number of nodes in tree if current node is the last node of complete binary tree
	// to derive val i will use same equation as complete binary tree.
	// If level of parent is n then it's left child will be (2*n)th node and it's right child will be (2*n+1)th node according to 1 based indexing.
    int solve(TreeNode* root, char dir, int currentLevel, int val, int levels){
        if(root == NULL) // return -1 to represent NULL
            return -1;
        if(currentLevel == levels) // return val as a possible answer.
            return val;
        
        int ans;
        if(dir == 'r'){
            ans = solve(root->right,'l',currentLevel+1,2*val+1,levels);
        }else{
            ans = solve(root->left,'l',currentLevel+1,2*val,levels);
        }
        
        // case 2->b.
        // skip nodes on right so now i will call on the left
        if(ans == -1){
            if(dir == 'l')
                return -1;
            else{
                return solve(root->left,'l',currentLevel+1,2*val,levels);
            }
        }else{ // case 2->a. skip nodes on left so i will call on right.
            if(dir == 'r')
                return ans;
            else{ // Case : 3
                int temp = solve(root->right,'r',currentLevel+1,2*val+1,levels);
                return temp == -1 ? ans : temp;
            }
        }
    }
    int countNodes(TreeNode* root) {
        int levels = getLevel(root); // get height of tree.
        
        int nodes = solve(root,'r',1,1,levels); // call solve function.
        
        return nodes == -1 ? 0 : nodes;
    }
};
