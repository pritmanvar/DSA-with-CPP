#include<bits/stdc++.h>

using namespace std;

// structure to represent a Node in tree
struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};

// to traverse tree by pre order
void pre_order(Node* root){
    if(root != NULL){
        cout << root->key << " "; // print the data of current
        pre_order(root->left); // calling for left subtree
        pre_order(root->right); // calling for right subtree
    }
}

// to traverse tree by in order
void in_order(Node* root){
    if(root != NULL){
        in_order(root->left); // calling for left subtree
        cout << root->key << " "; // print the data of current
        in_order(root->right); // calling for right subtree
    }
}

// to traverse tree by post order
void post_order(Node* root){
    if(root != NULL){
        post_order(root->left); // calling for left subtree
        post_order(root->right); // calling for right subtree
        cout << root->key << " "; // print the data of current
    }
}

// to find size of tree
int size(Node* root){
    if(root == NULL) // base case
        return 0;
    
    int Size = size(root->left); // calling for the left subtree
    Size += size(root->right); // calling for right subtree

    return Size+1; // returning size of both + 1( 1 is for current node)
}

int height(Node* root){
    if(root == NULL)
        return 0;

    int Height = height(root->right); // calling for right subtree
    Height = max(Height,height(root->left)); // calling for left subtree

    return Height+1; // returning maximum height + 1
}

int main() 
{
    // initializing tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);
    root->right->right->right = new Node(11);

    pre_order(root); // it will print the pre order 
    cout << endl;

    in_order(root); // it will print the in order 
    cout << endl;

    post_order(root); // it will print the post order 
    cout << endl;

    cout << size(root) << endl; // it will print the size of tree

    cout << height(root) << endl; // it will print the height of tree

    return 0;
}
