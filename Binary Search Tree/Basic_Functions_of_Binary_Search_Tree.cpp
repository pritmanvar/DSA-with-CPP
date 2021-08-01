#include<bits/stdc++.h>

using namespace std;
// Structure to represent a Node
struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int x){
        key = x;
        left = right = NULL;
    }
};

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// it will print tree in level order and print 'N' if there is NULL
void print_tree(Node* root){
    queue<Node*> q; // queue to traverse in level order
    q.push(root);

    // traversing level order
    while(q.empty() == false){
        int count = q.size();

        for(int i = 0; i < count; i++){
            // getting front element from queue
            Node* temp = q.front();
            q.pop();

            // if there is NULL then print 'N' else print its key
            if(temp == NULL) 
                cout << "N ";
            else
                cout << temp->key << " ";

            // adding childrens into queue
            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Insert Node recursively into BST
Node* insert_re(Node* root, int x){
    if(root == NULL) // if root is NULL then i will simplly return new Node
        return new Node(x);
    
    // if key of current node is smaller then new node will be on the right side
    if(root->key < x)
        root->right = insert_re(root->right,x);
    // if key of current node is larger then new node will be on the left side
    if(root->key > x)
        root->left = insert_re(root->left,x);
    
    // returning root after insertion
    return root;
}
// insert node iteratively
Node* insert_it(Node* root, int x){
    Node* curr = root;
    Node* parent = NULL;

    // we will insert new node at the end so i will go into depth till i get NULL
    while(curr != NULL){
        parent = curr; // mainting parent of current Node
    
        if(curr->key > x) // if key of current node is larger then new node should be on the left side
            curr = curr->left;
        else if(curr->key < x) // if key of current node is smaller then new node should be on the right side
            curr = curr->right;
        else // if key of curr is same as x means node whose key is x is already present so there is no need to add more so simplly return node
            return root;
    }
    if(parent == NULL) // parent is null means curr is null so simplly return new node
        return new Node(x);
    // we will check that i have to add new node at right or left and add node
    if(parent->key > x) 
        parent->left = new Node(x);
    else if(parent->key < x)
        parent->right = new Node(x);
    
    // return root after insertion
    return root;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// search for node recursively
Node* search_re(Node* root, int x){
    if(root == NULL)
        return NULL;
    // if x is smaller than key of root node then i will search for x in left subtree
    // if x is larger than key of root node then i will search for x in right subtree
    // if x is same as key of root node then i will return the root node
    if(root->key > x)
        return search_re(root->left,x);
    else if(root->key < x)
        return search_re(root->right,x);
    else
        return root;
}
Node* search_it(Node* root, int x){
    // if x is smaller than key of root node then i will search for x in left subtree
    // if x is larger than key of root node then i will search for x in right subtree
    // if x is same as key of root node then i will return the root node
    while(root != NULL){
        if(root->key > x)
            root = root->left;
        else if(root->key < x)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// this function will give new root after deleting a root
// new root will be smallest root in the right subtree
// because all other nodes in right subtree will be larger than it and since it is in right subtree so all nodes in left subtree will be smaller than it
Node* get_new_root(Node* root){
    Node* curr = root->right;
    while(curr != NULL && curr->left != NULL)
        curr = curr->left;
    
    return curr;
}
Node* remove(Node* root, int x){
    if(root == NULL) // if root is null then nothing to delete so return root as it is
        return NULL;
    
    if(root->key < x){ // if key of current node is smaller then required node should be on the right side
        root->right = remove(root->right,x); // setting modified subtree at right
    }else if(root->key > x){ // if key of current node is larger then required node should be on the left side
        root->left = remove(root->left,x); // setting modified subtree at left
    }else{ // if current node is same as required node
        if(root->left == NULL){ // if left subtree is NULL then simplly i will remove crurrent node and return its right node as root of modified subtree
            Node* temp = root->right;
            delete(root);
            return root->right;
        }else if(root->right == NULL){ // if right subtree is NULL then simplly i will remove crurrent node and return its left node as root of modified subtree
            Node* temp = root->left;
            delete(root);
            return root->left;
        }else{ // if both subtree is not NULL
            Node* temp = get_new_root(root); // getting new root
            root->key = temp->key; // changing value of current root to new root
            root->right = remove(root->right,temp->key); // removing new root from right subtree because new root is from right subtree 
        }
    }
    return root;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main() 
{
    int n;
    cout << "Enter the number of Nodes in the binary search tree\n";
    cin >> n;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Constructing BST
    cout << "Enter the " << n << " Nodes of binary search tree\n";
    Node* root = NULL;
    // insert Node recursively 
    for(int i = 0; i < n/2; i++){
        int temp;
        cin >> temp;
        root = insert_re(root,temp);
    }
    // insert Node iteratively
    for(int i = 0; i < n-n/2; i++){
        int temp;
        cin >> temp;
        root = insert_it(root,temp);
    }

    // BST after insertion operations
    print_tree(root);

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Search operation
    cout << "Enter the value of node which you want to search recursively\n";
    int x;
    cin >> x;
    Node* temp = search_re(root,x); // calling for search function
    if(temp)
        cout << "Node founded\n";
    else
        cout << "Node is not present in the BST\n";
    
    cout << "Enter the value of node which you want to search iteratively\n";
    cin >> x;
    temp = search_it(root,x); // calling for search function
    if(temp)
        cout << "Node founded\n";
    else
        cout << "Node is not present in the BST\n";

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Remove operation
    cout << "Enter the value which you want to delete from BST\n";
    cin >> x;
    root = remove(root,x);
    print_tree(root); // it will print BST after deleting a Node

    return 0;
}
