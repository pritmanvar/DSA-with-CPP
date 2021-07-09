/* Problem Link : https://practice.geeksforgeeks.org/problems/circular-linked-list/1#

Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/

bool isCircular(Node *head)
{
   // Your code here
   Node* slow = head; // we will move it by one
        Node* fast = head; // we will move it by two
        
        // if there is a circular linkedlist then this 2 pointers will surly meet at same node
        // because after every move distance between slow and fast will imcrement by 1
        // so if number of nodes in circular linkedlist is k then at perticular time distance between slow and fast will be x*k, where x is any positive integer
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
}
