// Problem Link : https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1/?track=P100-Binary%20Search%20Tree#
Node* insert_it(Node* root, int x){
    Node* curr = root;
    Node* parent = NULL;

    // we will insert new node at the end so i will go into depth till i get NULL
    while(curr != NULL){
        parent = curr; // mainting parent of current Node
    
        if(curr->data > x) // if key of current node is larger then new node should be on the left side
            curr = curr->left;
        else if(curr->data < x) // if key of current node is smaller then new node should be on the right side
            curr = curr->right;
        else // if key of curr is same as x means node whose key is x is already present so there is no need to add more so simplly return node
            return root;
    }
    if(parent == NULL) // parent is null means curr is null so simplly return new node
        return new Node(x);
    // we will check that i have to add new node at right or left and add node
    if(parent->data > x) 
        parent->left = new Node(x);
    else if(parent->data < x)
        parent->right = new Node(x);
    
    // return root after insertion
    return root;
}
Node* constructBst(int arr[], int n)
{
    Node* root = new Node(arr[0]);
    for(int i = 1; i < n; i++){
        root = insert_it(root,arr[i]); // i will insert every node into tree
    }
    return root;
}
