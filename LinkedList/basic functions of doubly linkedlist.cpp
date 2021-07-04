#include<bits/stdc++.h>

using namespace std;

// structure for represent node
struct Node{
    int data;
    Node* next;
    Node* previous;

    Node(int d){
        data = d;
        next = NULL;
        previous = NULL;
    }
};

// function to print linkedlist
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// function to add at begin
Node* add_begin(Node* head, int data){
    Node* temp = new Node(data);
    if(head == NULL) // corner case
        return temp;
    
    head->previous = temp;
    temp->next = head;

    return temp;
}

// function to add at end
Node* add_end(Node* head, int data){
    Node* temp = new Node(data);
    if(head == NULL) // corner case
        return temp;
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->previous = curr;
    return head;
}

// function to reverse the linkedlist
Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) // corner case
        return head;
    
    while(head->next != NULL){
        swap(head->next,head->previous); // swapint previous and next pointer to reverse the linkedlist
        head = head->previous;
    }
    swap(head->next,head->previous);
    return head;
}

// function to remove from begin
Node* remove_begin(Node* head){
    // corner cases
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete(head);
        return NULL;
    }

    Node* temp = head->next;
    temp->previous = NULL;
    delete(head);
    return temp;
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
    while(curr->next != NULL){
        curr = curr->next;
    }
    Node* temp = curr->previous;
    temp->next = NULL;
    delete(curr);
    return head;
}

int main() 
{
    int n;
    cout << "Enter the number of nodes in doubly linkedlist\n";
    cin >> n;

    int data;
    cout << "Enter the data of " << n << " nodes\n";
    cin >> data;
    Node* head = new Node(data);
    Node* curr = head;
    for(int i = 0; i < n-1; i++){
        cin >> data;
        Node* temp = new Node(data);
        curr->next = temp;
        temp->previous = curr;
        curr = curr->next;
    }

    cout << "Printed the doubly LinkedList\n";
    print(head);

    cout << "Enter the data which you want to add at the begin\n";
    cin >> data;
    head = add_begin(head,data);
    cout << "Doubly LinkedList after adding at begin\n";
    print(head);

    cout << "Enter the data which you want to add at the end\n";
    cin >> data;
    head = add_end(head,data);
    cout << "Doubly LinkedList after adding at end\n";
    print(head);

    cout << "Doubly LinkedList after reversing\n";
    head = reverse(head);
    print(head);

    cout << "Doubly LinkedList after removing from begin\n";
    head = remove_begin(head);
    print(head);

    cout << "Doubly LinkedList after removing from end\n";
    head = remove_end(head);
    print(head);

    return 0;
}
