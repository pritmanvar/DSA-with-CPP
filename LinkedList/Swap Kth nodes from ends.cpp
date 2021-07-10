/* Problem Link : https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1/?track=P100-Linked%20List&batchId=197#

   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
    }
  };*/
Node *swapkthnode(Node* head, int num, int K)
{
    //if k is more than number of nodes or kth node from beginning 
    //and end are same, we retuen the list.
    if (K > num) 
      return head;
    if(2*K-1 == num) return head;
    
    Node* x_prev = NULL;
    Node* x = head;
    
    Node* y_prev = NULL;
    Node* y = head;
    
    int count = K-1;
    
    //finding the kth node from the beginning of list. We also find node
    //previous of kth node because we need to update next pointer of 
    // the previous node. 
    while(count--){
        x_prev = x;
        x = x->next;
    }
    
    count = num - K;
    
    //similarly, finding the kth node from end and its previous node. kth node 
    //from end is (num-k+1)th node from beginning .
    while(count--){
        y_prev = y;
        y = y->next;
    }
    
    //if x_prev exists, then new next of it will be y.
    if(x_prev)
        x_prev->next = y;
    //if y_prev exists, then new next of it will be x.
    if(y_prev)
        y_prev->next = x;
    
    //we will swap the next pointers of x and y.    
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    //changing head pointers when k is 1 or num. 
    if(K == 1)
        return y;
    if(K == num)
        return x;
    return head;    
}
