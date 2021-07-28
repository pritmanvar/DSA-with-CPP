/* Problem Link : Problem Link : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
vector <int> zigZagTraversal(Node* root)
{
    // In this i will use 2 stacks to do zigzag traversal while doing level order traversal
    vector<int> ans; // to store answer
    stack<Node*> s1; // 1st stack
    stack<Node*> s2; // 2nd stack
    s2.push(root); // adding root in the 2nd stack
    
    int level = 0;
    while(s1.size() > 0 || s2.size() > 0){
        int count = s1.size()+s2.size(); // one of these will be 0 so it will contains size of the stack which is not empty
        
        // doing level order traversal
        // if number of level is even then we have to print it as it is because i have to reverse next one
        // else i will push reight node first because i want next level as it is
        for(int i = 0; i < count; i++){
            Node* temp;
            if(level%2 == 0){ // if level is even then push childs as it is
                temp = s2.top();
                s2.pop();
                
                if(temp->left)
                    s1.push(temp->left);
                if(temp->right)
                    s1.push(temp->right);
            }else{ // push right child first
                temp = s1.top();
                s1.pop();
                
                if(temp->right)
                    s2.push(temp->right);
                if(temp->left)
                    s2.push(temp->left);
            }
            
            ans.push_back(temp->data);
        }
        level++; // updating level for next one
    }
    return ans;
}
