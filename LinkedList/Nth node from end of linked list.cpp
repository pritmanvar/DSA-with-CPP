/* Problem Link : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* first = head;
       // we will move first pointer n steps ahead
       for(int i = 0; i < n; i++){
           if(first == NULL){ // if linkedlist has not n nodes then we will return -1
               return -1;
           }
           first = first->next;
       }
       
       Node* second = head;
       
       // now when 1st will be at null then 2nd will be at desired node
       while(first != NULL){
           second = second->next;
           first = first->next;
       }
       return second->data;
}
