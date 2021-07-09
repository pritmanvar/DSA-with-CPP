/* Problem Link : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};*/
void splitList(Node *head, Node **head1, Node **head2)
{
    
    Node* slow = head;
    Node* fast = head;
    *head1 = head;
    
    // finding mid point of linkedlist
    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // making new linkedlist
    if(fast->next == head){
        fast->next = slow->next;
        *head2 = slow->next;
        slow->next = head;
    }else{
        fast->next->next = slow->next;
        *head2 = slow->next;
        slow->next = head;
    }
}
