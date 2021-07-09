/* Problem Link : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
     
      Node is defined as
      struct Node {
        int data;
        struct Node *next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };*/
    Node* segregate(Node *head) {
        // used counting sort
        int arr[3] = {0};
        
        Node* curr = head;
        while(curr != NULL){
            if(curr->data == 0){
                arr[0]++;
            }else if(curr->data == 1){
                arr[1]++;
            }else{
                arr[2]++;
            }
            curr = curr->next;
        }
        curr = head;
        for(int i = 0; i < 3; i++){
            while(arr[i] != 0){
                curr->data = i;
                curr = curr->next;
                arr[i]--;
            }
        }
        return head;
    }
