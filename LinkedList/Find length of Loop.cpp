/*
Problem Link : https://practice.geeksforgeeks.org/problems/find-length-of-loop/1/?track=P100-Linked%20List&batchId=197#

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
int countNodesinLoop(struct Node *head)
{
    // used Floyd Cycle Detection algorithm to detect a loop
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    int count = 1;
    if(fast == NULL || fast->next == NULL) // loop is not present
        return 0;
    
    while(fast->next != slow){ // we will fix slow and move fast with one when it arrives back to slow we will return length
        fast = fast->next;
        count++;
    }
    return count;
}
