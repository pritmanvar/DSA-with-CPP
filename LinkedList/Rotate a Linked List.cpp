/*
Problem Link : https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/?track=P100-Linked%20List&batchId=197#

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
    Node* rotate(Node* head, int k)
    {
        Node* new_head;
        Node* current = head;
        for(int i = 0; i < k-1; i++){ // to get pointer of kth node
            current = current->next;
        }
        if(current->next == NULL) // if it is last node of linkedlist then there is no need to do anything
            return head;
        new_head = current->next; // after rotating new node will be (k+1)th node
        current->next = NULL; // current node will be last node so making its next NULL
        current = new_head; // to traverse remaining linkedlist
        
        while(current->next != NULL){ // to get the pointer of last node
            current = current->next;
        }
        current->next = head; // connecting first k node at last
        
        return new_head;
    }
