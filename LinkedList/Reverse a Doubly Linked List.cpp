/*Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }  
};*/
Node* reverseDLL(Node * head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* pre = NULL;
    Node* next = head->next;
    while(head != NULL){
        pre = head;
        swap(head->next,head->prev); // will swap previous and next pointer to reverse the linkedlist
        head = head->prev;
    }
    return pre;
}
