#include<bits/stdc++.h>

using namespace std;

// structure which represents Node.
struct Node{
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

// function to print linkedlist with help of recursion
void rprint(Node* head){
    if(head == NULL)
        return;
    cout << head->data << " ";
    rprint(head->next);
}

// function to print linkedlist with help of loop
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

// function to search position of node in linkedlist with help of loop
// returns -1 if node not found
int search(Node* head, int val){
    int pos = 1;
    while(head != NULL){
        if(head->data == val){
            return pos;
        }
        pos++;
        head = head->next;
    }
    return -1;
}

// function to search position of node in linkedlist with help of recursion
// returns -1 if node not found
int rsearch(Node* head, int val){
    if(head == NULL)
        return -1;
    if(head->data == val)
        return 1;
    int pos = rsearch(head->next,val);
    if(pos == -1)
        return -1;
    return pos+1;
}

// function to add node at begin
Node* insert_begin(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

// function to add node at end
Node* insert_end(Node* head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        return temp;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// Function to remove node from begin
Node* remove_first(Node* head){
    if(head == NULL)
        return NULL;
    Node* temp = head->next;
    delete(head);
    return temp;
}

// Function to remove node from end
Node* remove_last(Node* head){
    if(head == NULL || head->next == NULL)
        return NULL;
    Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = NULL;
    return head;
}
int main() 
{
    int n;
    cout << "Enter the number of Nodes in LinkedList\n";
    cin >> n;

    cout << "Enter the data of " << n << " Nodes\n";
    int data;
    cin >> data;
    Node* head = new Node(data);
    Node* last = head;
    // cout << new Node << endl;
    for(int i = 0; i < n-1; i++){
        cin >> data;
        Node* temp = new Node(data);
        last->next = temp;
        last = last->next;
    }
    int val;
    cout << "Printing using loop\n";
    print(head);
    
    cout << "\nPrinting using recursion\n";
    rprint(head);
    
    cout << "\nEnter the value for which you want to search with help of loop\n";
    cin >> val;
    cout << search(head,val) << endl;

    cout << "Enter the value for which you want to search with help of recursion\n";
    cin >> val;
    cout << rsearch(head,val) << endl;

    cout << "Enter the value which you want to insert at begin\n";
    cin >> val;
    head = insert_begin(head,val);
    cout << "After inserting at begin\n";
    print(head);

    cout << "\nEnter the value which you want to insert at end\n";
    cin >> val;
    head = insert_end(head,val);
    cout << "After inserting at end\n";
    print(head);

    cout << "\nAfter removing first node \n";
    head = remove_first(head);
    print(head);

    cout << "\nAfter removing last node \n";
    head = remove_last(head);
    print(head);
    return 0;
}
