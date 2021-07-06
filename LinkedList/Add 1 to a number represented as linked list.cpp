/* 
Problem Link : https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
    Node* addOne(Node *head) 
    {
        Node* current = head;
        Node* less_than_nine = NULL; // it will store the address of last node whose value is less than 9
        while(current != NULL){ // traverse whole linkedlist and find last node whose value is less than 9
            if(current->data < 9){
                less_than_nine = current;
            }
            current = current->next;
        }
        
        if(less_than_nine == NULL){ // control goes in this condition means value of every node is 9
            Node* temp = new Node(1); // adding node whose value is 1 at begining
            temp->next = head;
            
            less_than_nine = head; // moving one step ahead
            head = temp; // making temp as new head
        }else{
            less_than_nine->data++; // adding one to last node whose vause is less than 9
            less_than_nine = less_than_nine->next; // moving one step ahead
        }
        
        // making value 0 of all nodes who is after thi last node whose value is nine
        while(less_than_nine != NULL){
            less_than_nine->data = 0;
            less_than_nine = less_than_nine->next;
        }
        return head;
    }
