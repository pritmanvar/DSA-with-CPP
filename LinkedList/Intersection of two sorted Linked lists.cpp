/* The structure of the Linked list Node is as follows:
Problem Link : https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};*/
Node* findIntersection(Node* head1, Node* head2)
{
    Node* head = NULL; // head of required linkedlist
    Node* current = head; // to traverse both linkedlisst
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data > head2->data){ // if data of head1 greater than head2 then we will move ahead in head2
            head2 = head2->next;
        }else if(head1->data < head2->data){ // if data of head2 greater than head1 then we will move ahead in head1
            head1 = head1->next;
        }else{ 
            if(current == NULL){ // this is 1st same node then make it head of required linkedlist
                head = head1;
                current = head1;
            }else{ // add current node at the last of head linkedlist
                current->next = head1;
                current = current->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return head;
}
