/* Problem Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
    
    struct Node {
        int data;
        Node *left;
        Node *right;
    
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };*/
    int count = 0; // it will show that current node is (count)th max node
    int ans = -1; // to store answer
    
    // i will traverse my tree in inorder i will increment count
    // as i find that count == k
    // i will mark my answer as data of that node
    void solve(Node* root, int k){
        if(root == NULL)
            return;
        
        solve(root->left,k);
        count++;
        if(k == count){
            ans = root->data;
            return;
        }
        solve(root->right,k);
    }
    int KthSmallestElement(Node *root, int K)
    {
        // reseting global variables
        count = 0;
        ans = -1;
        solve(root,K); // calling for function
        return ans; // returning answer
    }
