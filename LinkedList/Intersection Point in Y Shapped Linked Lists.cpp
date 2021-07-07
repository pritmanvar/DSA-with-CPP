/*Problem Link : https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n1 = 0; // number of nodes in head1
    int n2 = 0; // number of nodes in head2
    Node* h1 = head1;
    Node* h2 = head2;
    
    while(h1 != NULL){ // counting number of nodes in head1
        n1++;
        h1 = h1->next;
    }
    
    while(h2 != NULL){ // counting number of nodes in head2
        n2++;
        h2 = h2->next;
    }
    
    h1 = head1;
    h2 = head2;
    
    // removing extra nodes
    if(n1 > n2){
        for(int i = 0; i < n1-n2; i++){
            h1 = h1->next;
        }
    }else{
        for(int i = 0; i < n2-n1; i++){
            h2 = h2->next;
        }
    }
    
    
    while(h1 != h2){
        h1 = h1->next;
        h2 = h2->next;
    }
    // returning data of common node
    return h1->data;
}
