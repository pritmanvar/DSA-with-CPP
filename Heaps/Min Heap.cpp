#include<bits/stdc++.h>

using namespace std;

// structure for min Heap
struct Heap{
    vector<int> arr; // vector that will work as heap

    // constructures
    Heap(){
        arr.clear();
    }
    Heap(vector<int> a){
        arr = a;
    }

    // function to print current state of Heap
    void display_heap(){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // it will return index of parent of value at ith index
    int get_parent(int i){
        if(i <= 0 || i >= arr.size())
            return -1;
        return (i-1)/2;
    }
    // it will return index of left child of value at ith index
    int get_left_child(int i){
        return (2*i+1) < arr.size() ? 2*i+1 : -1;
    }
    // it will return index of right child of value at ith index
    int get_right_child(int i){
        return (2*i+2) < arr.size() ? 2*i+2 : -1;
    }
    // if element at ith index is smaller then its parent then this function will make heap balance
    void heapify_up(int i){
        int p = get_parent(i);
        if(p == -1 || arr[i] >= arr[p])
            return;
        
        swap(arr[i],arr[p]); 
        heapify_up(p);
    }
    // to insert new data in the heap
    // i will insert data at the end and call heapify_up function to balance heap
    void insert(int n){
        arr.push_back(n);
        heapify_up(arr.size()-1);
    }
    // it will return minimum element of heap
    int front(){
        return arr[0];
    }
    // if element at ith index is larger then its children then this function will make heap balance
    void heapify_down(int i){
        int cl = get_left_child(i);
        int cr = get_right_child(i);
        int mn = i;
        if(cl != -1 && arr[mn] > arr[cl]){
            mn = cl;
        }
        if(cr != -1 && arr[mn] > arr[cr]){
            mn = cr;
        }
        if(mn == i)
            return;
        swap(arr[i],arr[mn]);
        heapify_down(mn);
    }
    // to pop minimum data in the heap
    // i will copy data of last node at 0th index and then remove last data
    // after that i will call for deapify_down for 0th index to make heap balanced
    void pop(){
        if(arr.size() == 0)
            return;
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        heapify_down(0);
    }
    // if current array is not a heap then this function will make that heap
    // in this i will start making heap from bottom most left most parent 
    // for each parent i will call heapify_down function 
    void make_heap(){
        for(int i = (arr.size()-2)/2; i >= 0; i--){
            heapify_down(i);
        }
    }
};
int main() 
{
    Heap* hp = new Heap(); // declaring new Heap
    
    cout << "Enter the number of elements you want to add in the Heap\n";
    int n;
    cin >> n;

    cout << "Enter the " << n << " elements of Heap\n";
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        hp->insert(temp); // Inserting every data into the Heap
    }
    hp->display_heap(); // display Heap

    cout << "Minimum element in Heap is : " << hp->front() << endl;

    // to remove minimum element from Heap
    hp->pop();
    hp->display_heap(); // display Heap

    // creating new heap which is not balanced
    hp = new Heap({5,6,4,7,3,8});
    hp->make_heap(); // calling for make_heap function to stable Heap properties
    hp->display_heap(); // display heap
    return 0;
}
