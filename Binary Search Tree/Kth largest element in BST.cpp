/* Problem Link : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#
    
    The Node structure is defined as
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
    
    // i will traverse my tree in reverse order and in inorder i will increment count
    // as i find that count == k
    // i will mark my answer as data of that node
    void solve(Node* root, int k){
        if(root == NULL)
            return;
        
        solve(root->right,k);
        count++;
        if(k == count){
            ans = root->data;
            return;
        }
        solve(root->left,k);
    }
    int kthLargest(Node *root, int K)
    {
        // reseting count
        count = 0; 
        ans = -1;
        solve(root,K); // calling for function
        return ans; // returning answer
    }
