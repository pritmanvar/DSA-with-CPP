// Problem Link : https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#
    
    // struct Node {
    // int data;
    // Node *next;
    // Node *arb;

    // Node(int x) {
    //     data = x;
    //     next = NULL;
    //     arb = NULL;
    // }
    // };
    Node *copyList(Node *head)
    {
        
        Node* curr = head;
        // we will add new node after every node which will contain same value
        while(curr != NULL){
            Node* temp = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = temp;
            curr = curr->next->next;
        }
        curr = head;
        // with help of current node we will set arb pointer of node which we have added
        while(curr != NULL){
            if(curr->arb != NULL)
                curr->next->arb = curr->arb->next;
            else
                curr->next->arb = NULL;
            curr = curr->next->next;
        }
        curr = head;
        
        Node* answer = head->next; // new head
        
        // we will break connection between new and old nodes
        while(curr != NULL && curr->next != NULL){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            curr = temp;
        }
        return answer;
    }
