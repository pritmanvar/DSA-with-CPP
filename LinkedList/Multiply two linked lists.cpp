/* Problem Link : https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#

Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    //Your code here
    long long int num1 = 0;
    long long int num2 = 0;
    
    // converted both linkedlist into numbers and done multiplication while taking care about modulo
    
    while(l1 != NULL){
        num1 = (num1*10)%1000000007 + l1->data;
        l1 = l1->next;
    }
    while(l2 != NULL){
        num2 = (num2*10)%1000000007 + l2->data;
        l2 = l2->next;
    }
    return ((num1%1000000007)*(num2%1000000007))%1000000007;
}
