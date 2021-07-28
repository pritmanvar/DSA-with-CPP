/*  Problem Link : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans; // to store simple level order traversal
    vector<int> size; // to store size of each level
    queue<Node*> q; // queue for the level order traversal
    
    // simple level order traversal
    q.push(root);
    while(q.size() != 0){
        int count = q.size();
        size.push_back(count);
        
        for(int i = 0; i < count; i++){
            Node* temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    // Now i will convert simple level order traversal to reverse level order traversal
    int count = 0; // number of nodes which are reversed
    
    // i will reverse each level
    for(int i = 0; i < size.size(); i++){
        reverse(ans.begin()+count,ans.begin()+count+size[i]); // reversing ith level
        count += size[i];
    }
    
    // reversing all array
    // by this last level will becaome first and we have reversed every level so now they will become normal
    reverse(ans.begin(),ans.end());
    return ans;
}
