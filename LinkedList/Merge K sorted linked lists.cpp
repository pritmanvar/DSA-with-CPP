/* Problem Link : https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/?track=P100-Linked%20List&batchId=197#
    
    Linked list Node structure
    struct Node
    {
    	int data;
    	Node* next;
    	
    	Node(int x){
    	    data = x;
    	    next = NULL;
    	}
    };*/ 
    
    // merge function of merge sort
    Node* merge(Node* h1, Node* h2){
        
        Node* new_head = NULL;
        Node* curr = NULL;
        
        while(h1 != NULL && h2 != NULL){
            if(h1->data <= h2->data){
                if(curr == NULL){
                    curr = h1;
                    new_head = h1;
                }else{
                    curr->next = h1;
                    curr = curr->next;
                }
                h1 = h1->next;
            }else{
                if(curr == NULL){
                    curr = h2;
                    new_head = h2;
                }else{
                    curr->next = h2;
                    curr = curr->next;
                }
                h2 = h2->next;
            }
        }
        
        if(h1 != NULL){
            curr->next = h1;
        }else{
            curr->next = h2;
        }
        
        return new_head;
    }
    
    // Main function
    Node * mergeKLists(Node *arr[], int k)
    {
           Node* head = arr[0];
           
           // we will merge k lists in the group of 2
           for(int i = 1; i < k; i++){
               head = merge(head,arr[i]);
           }
           return head;
    }
