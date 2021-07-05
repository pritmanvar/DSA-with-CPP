#include<bits/stdc++.h>

using namespace std;

// structure for represent node
struct Node{
    int data;
    Node* next;
};

// function to print circular linkedlist
void print(Node* head){
    if(head == NULL) // corner case
        return;
    Node* temp = head;
    // we will run loop while wi reach at the starting
    do{
        cout << head->data << " ";
        head = head->next;
    }while(head != temp);
    cout << endl;
}

// function to add at begin
Node* add_begin(Node* head, int data){
    Node* temp = new Node(); // created node of data
    temp->data = data;
    temp->next = temp;

    if(head == NULL) // corner case
        return temp;
    
    Node* cpy = head->next; // adding node at the next of head
    head->next = temp; 
    temp->next = cpy;

    // swaping data of head and temp so now data of new node will stored by head 
    swap(head->data,temp->data); 

    return head;
}

// function to add at end
Node* add_end(Node* head, int data){
    Node* temp = new Node();// created node of data
    temp->data = data;
    temp->next = temp;

    if(head == NULL) // corner case
        return temp;

    Node* cpy = head->next; // adding node at the next of head
    head->next = temp;
    temp->next = cpy;

    // swaping data of head and temp so now data of new node will stored by head 
    swap(head->data,temp->data);

    // as head returning new node so node who has new data becomes last node
    return temp;
}

// function to reverse the circular linkedlist
Node* reverse(Node* head){
    if(head == NULL || head->next == head) // corner case
        return head;
    
    Node* cpy = head; // it will use to terminate the loop
    Node* pre = head; // to store previous of current node
    head = head->next; // moving head 1 step ahead 
    Node* next; // tu store next of current node
    
    while(head != cpy){ // if we come back to head then terminate the looop
        next = head->next; // moving next ahead 
        head->next = pre; // changing direction of next pointer of current node to previous node
        pre = head; // moving precious ahead
        head = next; // moving head ahead
    }

    // we haven't change the direction of next pointer of 1st node so doing that

    // returning last node as new head
    head->next = pre;
    return pre;
}

// function to remove from begin
Node* remove_begin(Node* head){
    if(head == NULL) // corner cases
        return NULL;

    if(head->next == NULL){ // corner case
        delete(head);
        return NULL;
    }

    head->data = head->next->data; // coping data of next node into head
    Node* temp = head->next; // save the data of next node
    head->next = head->next->next; // removing next node. it is safe because data of next node is in the head
    delete(temp); // deleting next node
    return head;
}

// function to remove from end
Node* remove_end(Node* head){
    // corner cases
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete(head);
        return NULL;
    }

    Node* curr = head;
    while(curr->next->next != head){ // going to previous node of lase node
        curr = curr->next;
    }

    // removing and deleting last node
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);

    return head;
}

int main() 
{
    int n;
    cout << "Enter the number of nodes in circular linkedlist\n";
    cin >> n;

    int data;
    cout << "Enter the data of " << n << " nodes\n";
    cin >> data;
    Node* head = new Node();
    head->data = data;
    head->next = head;
    Node* curr = head;
    for(int i = 0; i < n-1; i++){
        cin >> data;
        Node* temp = new Node();
        temp->data = data;
        curr->next = temp;
        temp->next = head;
        curr = curr->next;
    }

    cout << "Printed the circular LinkedList\n";
    print(head);

    cout << "Enter the data which you want to add at the begin\n";
    cin >> data;
    head = add_begin(head,data);
    cout << "circular LinkedList after adding at begin\n";
    print(head);

    cout << "Enter the data which you want to add at the end\n";
    cin >> data;
    head = add_end(head,data);
    cout << "circular LinkedList after adding at end\n";
    print(head);

    cout << "circular LinkedList after reversing\n";
    head = reverse(head);
    print(head);

    cout << "circular LinkedList after removing from begin\n";
    head = remove_begin(head);
    print(head);

    cout << "circular LinkedList after removing from end\n";
    head = remove_end(head);
    print(head);

    return 0;
}
