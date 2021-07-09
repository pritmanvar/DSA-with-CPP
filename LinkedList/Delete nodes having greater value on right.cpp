/* Problem Link : https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
    
    The structure of linked list is the following
    struct Node
    {
        int data;
        Node* next;
        
        Node(int x){
            data = x;
            next = NULL;
        }
    };*/
    
    // reverse the linkedlist
    Node* reverse(Node* head){
        Node* pre = NULL;
        Node* next = head;
        Node* curr = head;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    Node *compute(Node *head)
    {
        // we had reversed the linkedlist because now we can fix our head because after last node there isn't any node whose data is greater than last node
        head = reverse(head);
        Node* curr = head;
        
        while(curr != NULL && curr->next != NULL){
            // if data of next is smaller than current then we will remove next node
            if(curr->data > curr->next->data){
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }else{
                curr = curr->next;    
            }
        }
        // reversing befor return because we have reversed ago
        return reverse(head);
    }
