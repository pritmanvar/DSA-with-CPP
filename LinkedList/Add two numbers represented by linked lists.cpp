/* node for linked list:
    Problem Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
    
    struct Node {
        int data;
        struct Node* next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };*/
    
    // function to reverse the LinkedList
    Node* reverse(Node* head){
        if(head == NULL || head->next == NULL)
            return head;
        
        Node* pre = NULL;
        Node* current = head;
        Node* Next = current;
        while(current != NULL){
            Next = Next->next;
            current->next = pre;
            pre = current;
            current = Next;
        }
        return pre;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // reversing both LinkedList
        first = reverse(first);
        second = reverse(second); 
        
        // we will store our answer in the first linkedlist so our new head will be first
        Node* new_head = first;
        int carry = 0; // to store carry
        int sum; // to store sum of current digits
        Node* previous = NULL; // to take track of previous node
        
        // update every variable while we reach at the end of any linkedlist
        while(first != NULL && second != NULL){
            int sum = first->data + second->data + carry;
            first->data = sum%10; 
            carry = sum/10; 
            previous = first;
            first = first->next;
            second = second->next;
        }
        
        // we will go inside if second is NULL so adding carry in data of first
        while(first != NULL){
            sum = first->data + carry;
            first->data = sum%10;
            carry = sum/10;
            previous = first;
            first = first->next;
        }
        
        // we will go inside if first is NULL so adding carry in data of srcond and connect node of that data at the last of first
        while(second != NULL){
            previous->next = new Node((second->data + carry)%10);
            previous = previous->next;
            carry = (second->data + carry)/10;
            second = second->next;
        }
        
        // we will go inside if first and second is NULL so adding carry connect node of that data at the last of first
        while(carry != 0){
            previous->next = new Node(carry%10);
            previous = previous->next;
            carry /= 10;
        }
        previous->next = NULL; // making next of last node NULL
        
        // we had performed all operations on the reversed linkedlist so reversing again to get required answer
        new_head = reverse(new_head);
        
        return new_head;
    }
