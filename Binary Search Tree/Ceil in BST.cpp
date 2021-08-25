// Problem Link : https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1/?track=P100-Binary%20Search%20Tree&batchId=197#

// there are 2 major cases and after that there are some subcases
// 1. data of current node is less or equal to input
//      a. data of current node is equal to input 
//          in this case i will return current node because i can't get any node whose data is larger than input and smaller than current node since my current node is equal to input 
//      b. Right child of my current node is NULL
//          here data of current node is smaller than input and there isn't any larger data than current one so i will return -1
//      c. Right child is not NULL
//          here data of current node is smaller than input so i will call findCeil function for the right subtree to get it's ceill value since right subtree contains larger data then current one
// 2. Data of current node is greater than key
//      a. left of current root is NULL
//          in this case there is not any possibility that i can get smaller value which is larger than input so answer will be data of current node
//      b. left is not NULL
//          in this case i will call findCeill function for left child and see that can i get smaller ceil than current one
//          if there is smaller ceill then i will return that else i will return data of current node
int findCeil(Node* root, int input) 
{ 
    if(root->data <= input){
        if(root->data == input)
            return input;
        else if(root->right == NULL)
            return -1;
        else
            return findCeil(root->right, input);
    }else{
        if(root->left == NULL){
            return root->data;
        }else{
            int pos = findCeil(root->left, input);
            if(pos == -1)
                return root->data;
            else
                return pos;
        }
    }
} 
