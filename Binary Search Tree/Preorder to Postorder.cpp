// Problem Link : https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1#

Node* construct(int pre[], int size, int l, int r){
    if(l > r) // base case
        return NULL;
    
    // first element of range will be head of tree.
    Node* head = new Node();
    head->data = pre[l];
    
    // alll smaller elements than head will be go to it's left side and others will be go to it's right side.
    int i = l+1;
    while(i < size && pre[i] < pre[l]){
        i++;
    }
    // call for it's left and right with valid range.
    head->left = construct(pre,size,l+1,i-1);
    head->right = construct(pre,size,i,r);
    
    return head; // return head of tree.
}
Node* post_order(int pre[], int size)
{
    return construct(pre,size,0,size-1);
}
