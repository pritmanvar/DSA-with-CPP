/* Problem Link : https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#

A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
vector<int> path_for_a; // it will store path from root to a
vector<int> path_for_b; // it will store path from root to b
    
void NodeToRootPath(Node* root, vector<int> path, int n1, int n2){
    if(root == NULL) // base case
        return;
    
    path.push_back(root->data); // adding root into current path
    // if current node is equal to n1 then set current path at path_for_n1
    if(root->data == n1){
        path_for_a = path;
    }
    // if current node is equal to n2 then set current path at path_for_n2
    if(root->data == n2){
        path_for_b = path;
    }
    
    // calling for left and right subtree
    NodeToRootPath(root->left, path, n1, n2);
    NodeToRootPath(root->right, path, n1, n2);
    
    // removing current node from path because i am leaving it
    path.pop_back();
}
int findDist(Node* root, int a, int b) {
    // clearing both path at starting from code
    path_for_a.clear();
    path_for_b.clear();
    
    // calling function to fill both path vectors
    vector<int> path;
    NodeToRootPath(root, path, a , b);
    
    // i will count number of same nodes in both path because they will not included min distance path
    int count = 0;
    for(int i = 0; i < min(path_for_a.size(),path_for_b.size()); i++){
        if(path_for_a[i] != path_for_b[i])
            break;
        
        count++;
    }
    
    // min distance will be sum of size of both path vectors - 2*(number of same nodes)
    return path_for_a.size()+path_for_b.size()-2*count;
}
