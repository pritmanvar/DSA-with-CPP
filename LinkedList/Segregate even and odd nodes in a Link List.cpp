/* Problem Link : https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
    
    struct Node
    {
        int data;
        struct Node* next;
        
        Node(int x){
            data = x;
            next = NULL;
        }
    };*/
    Node* divide(int N, Node *head){
        // code here
        Node* odd = NULL;
        Node* even = NULL;
        Node* ho = NULL; // head of odd
        Node* he = NULL; // head of odd
        bool o = true; // it will help to mark head of odd
        bool e = true; // it will help to mark head of even
        
        while(head != NULL){
            if(head->data%2 == 0){ // if data is even then we will add that in even linkedlist
                if(e){
                    even = head;
                    he = head;
                    e = false;
                }else{
                    even->next = head;
                    even = even->next;
                }
            }else{ // if data is odd then we will add that in odd linkedlist
                if(o){
                    odd = head;
                    ho = head;
                    o = false;
                }else{
                    odd->next = head;
                    odd = odd->next;
                }
            }
            head = head->next;
        }
        
        // connecting both linkedlist
        if(odd)
            odd->next = NULL;
        else
            even->next = NULL;
        if(even)
            even->next = ho;
        else
            return ho;
        return he;
    }
