// Problem Link : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
    
    /*struct Node
    {
        int data;
        Node* next;
        
        Node(int val)
        {
            data = val;
            next = NULL;
        }
    };*/
    void removeLoop(Node* head)
    {
        // checking that is there any loop present in LinkedList
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                break;
            }
        }
        
        // if loop is not present then simply return without doing anything
        if(fast == NULL || fast->next == NULL)
            return;
        // if loop starts from head
        if(fast == head){
            // go to the last node and make it's next pointer to NULL to remove the loop
            while(fast->next != slow)
                fast = fast->next;
            fast->next = NULL;
            return;
        }
        // m = number of nodes before loop
        // k = number of node from starrting of loop after which slow and fast are met
        // x = slow has traveled loop x times
        // y = fast has traveled loop y times
        // n = number of nodes in the loop
        
        // distance traveled by slow*2 == distance traveled by fast
        // (m + k + x*n)*2 == (m + k + y*n)
        // (m + k) = y*n - 2*x*n
        // (m + k) = n(y - 2*x)
        // here all things are integer so (m+k) is multipayer of n
        
        // if we put slow at head then it has to travel m nodes to come at starting of loop
        // and fast has to traverse n-k nodes but (m+k) is multipayer of n so m+k-k == m
        slow = head;
        
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
