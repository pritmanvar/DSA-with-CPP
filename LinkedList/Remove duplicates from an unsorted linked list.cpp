/*
Problem Link : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#

The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
    Node * removeDuplicates( Node *head) 
    {
        if(head == NULL || head->next == NULL) // corner case
            return head;

        unordered_set<int> st; // to store present data till now
        Node* current = head;
        
        while(current != NULL && current->next != NULL){
            st.insert(current->data); // adding this data into the set
            
            // if data of next node is present then we will remove that node from linkedlist
            if(st.count(current->next->data) == 1){
                Node* temp = current->next;
                current->next = current->next->next;
                delete(temp);
            }else{ // moving to next node
                current = current->next;
            }
        }
        return head;
    }
