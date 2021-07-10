/* Problem Link : https://practice.geeksforgeeks.org/problems/pairwise-swap-of-nodes-in-linkelist/1/?track=P100-Linked%20List&batchId=197#

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        swap(curr->data,curr->next->data); // we will swap data of 2 consicutive elements
        curr = curr->next->next;
    }
    return head;
}
