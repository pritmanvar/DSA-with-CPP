/* Problem Link : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#

BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};*/
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = suc = NULL; // i will initilize NULL to both
    Node* curr = root;
    
    while(curr){
        // if value of current node is greater then key then it can be successor so mark it as suc and go to left to find smaller successor 
        if(curr->key > key){
            suc = curr;
            curr = curr->left;
        }else{ // if it is smaller then go to right to get successor 
            curr = curr->right;
        }
    }
    curr = root;
    while(curr){
        // if value of current node is smaller then key then it can be predecessor so mark it as pre and go to right to find larger predecessor  
        if(curr->key < key){
            pre = curr;
            curr = curr->right;
        }else{ // if it is larger then go to left to get predecessor 
            curr = curr->left;
        }
    }
}
