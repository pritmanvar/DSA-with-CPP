/* Problem Link : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
    
    struct Node {
      int data;
      struct Node *next;
      Node(int x) {
        data = x;
        next = NULL;
      }
    };*/
    
    // to reverse a linkedlist
    Node* reverse(Node* head){
        if(head == NULL || head->next == NULL)
            return head;
        
        Node* pre = NULL;
        Node* next = head;
        
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(Node *head)
    {
        // we will move to the mid point of linkedlist and the reverse one half
        // of both half are identical then given linkedlist is palindrome
        Node* slow = head;
        Node* fast = head;
        Node* pre = NULL;
        while(fast != NULL && fast->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(pre != NULL)
        pre->next = NULL;
        
        // reversing 1 half
        slow = reverse(slow);
        
        // to check that both are identical or not
        while(slow != NULL && head != NULL){
            if(slow->data != head->data){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
