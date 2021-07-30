/* Problem Link : https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#
    
    A binary tree node
    struct Node
    {
        int data;
        Node* left, * right;
    }; */
    // this function will find sum of both subtree and set it to corrosponding node
    int convert(Node* node){
        if(node == NULL){ // base case
            return 0;
        }
        
        int sum = convert(node->left); // finding sum of left subtree
        sum += convert(node->right); // finding sum of right subtree
        sum += node->data; // adding value of current node into sum
        
        node->data = sum - node->data; // i have to set sum  of left subtree and right subtree so substracting value of current node form sum
        
        return sum; // return sum for the parent
    }
    void toSumTree(Node *node)
    {
        // calling to convert function
        convert(node);
    }
