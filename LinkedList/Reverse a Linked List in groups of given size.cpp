// Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#
    
    /* Reverse a linked list
    The input list will have at least one element  
    Return the node which points to the head of the new LinkedList
    Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head; */
    struct node *reverse (struct node *head, int k)
    { 
        node* pre = NULL; // to store previous of current node
        node* new_head = NULL; // new head
        node* last = head; // it will be last node after reversing k nodes
        node* curr = head; // represents the current node which we are reversing
        // it is safe because k <= n
        for(int i = 0; i < k; i++){
            node* next = curr->next; // to take handle of next node
            curr->next = pre; // reversing pointer of current node to previous node
            // moving ahead to previous pointer and current pointer
            pre = curr;
            curr = next;
        }
        new_head = pre; // marking new head.
        while(curr != NULL){
            node* temp = curr; // it will be last node after reversing k nodes
            pre = NULL; 
            
            // same as upper loop but now we will take care that curr doesn't become NULL
            for(int i = 0; i < k && curr != NULL; i++){
                node* next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            last->next = pre; // connecting this reversed linkedlist with linkedlist which is reversed before
            last = temp; // updating last node for the next reversed linkedlist
        }
        return new_head;
    }
