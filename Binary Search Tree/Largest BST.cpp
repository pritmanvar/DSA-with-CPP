/* Problem Link : https://practice.geeksforgeeks.org/problems/largest-bst/1#

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


// Return the size of the largest sub-tree which is also a BST

// I will call for solve which will return vector of 4 elements
//   Meaning of ith index is : 
//     0-> tree is BST of not
//     1-> minimum value of tree
//     2-> maximum value of tree
//     3-> size of tree
// during the post order i will check that current tree is BST or not 
// and if it is BST then i will count it's size after that i will try to update ans which will be global variable

int ans = 0; // will store answer 
vector<int> solve(Node* root){
    // if root is NULL then it is BST so 0th index will be 1 and 
    // ans i will mark min indes with +ind and max index with 0 because 0 is least possible data in this tree
    if(root == NULL)
        return {1,INT_MAX,0,0};
    
    // calling for solve function for left and right tree
    vector<int> left = solve(root->left);
    vector<int> right = solve(root->right);
    vector<int> curr(4); // declaring vector for current tree
    
    // If both subtree of current tree is BST
    // and data of current node is larger than maximum data of left subtree and smaller than minimum data of right subtree then current tree is alse BST
    if(left[0] == 1 && right[0] == 1 && (left[2] < root->data) && (right[1] > root->data)){
        curr[0] = 1;
        curr[1] = min(left[1],root->data);
        curr[2] = max(right[2],root->data);
        curr[3] = left[3] + right[3] + 1;
        ans = max(ans,curr[3]);
    }
    // it is is not BST then it's 0th index will be 0 so there is no need to do anything 
    return curr; // returning data of current tree to its parent
}
int largestBst(Node *root)
{
    ans = 0; // reseting answer
    solve(root); // calling for solve function
    return ans; // return answer
}
