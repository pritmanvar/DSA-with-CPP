/* Problem Link : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

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
};*/
vector<int> leftView(Node *root)
{
    // I will do level order traversal and while traversing i will push back 1st node of every level into ans
    
    vector<int> ans; // to store answer
    queue<Node*> q; // queue for the level order traversal
    
    // Corner case
    if(root == NULL)
        return ans;
    
    // level order traversal
    q.push(root);
    while(q.size() > 0){
        int count = q.size();
        
        for(int i = 0; i < count; i++){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
            if(i == 0){ // if it is 1st node then add it into ans
                ans.push_back(temp->data);
            }
        }
    }
    // return the answer
    return ans;
}
