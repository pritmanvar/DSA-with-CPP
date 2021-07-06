/*
Problem Link : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/
Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(head == NULL) // cornet case
        return NULL;
    
    Node* current = head; // to traverse the linkedlist
    
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data){ // if to consecutive node has same data then we will remove one
            Node* temp = current->next;
            current->next = current->next->next;
            delete(temp);
        }else{ // we will not increment in every case because in that we will miss the case when more than 2 consecutive nodes have same value
            current = current->next;
        }
    }
    return head;
}
