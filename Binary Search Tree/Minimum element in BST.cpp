// Problem Link : https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1#
int minValue(Node* root)
{
    int min = -1; // initilizing answer
    
    // i will move to left as possible because according to properties of bst min element will be at left side
    while(root != NULL){
        min = root->data;
        root = root->left;
    }
    
    return min; // return answer
}
