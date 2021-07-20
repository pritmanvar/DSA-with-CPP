#include<bits/stdc++.h>

using namespace std;
struct Dequeue{
    list<int> ls; // linkedlist to build a queue
    int sz;
    Dequeue(){
        sz = 0;
    }

    // add x at the end of queue
    void push_back(int x){
        sz++;
        ls.push_back(x);
    }
    // add x at the front of queue
    void push_front(int x){
        sz++;
        ls.push_front(x);
    }
    // remove the element at front from queue
    void pop_front(){
        if(sz == 0)
            return;
    
        ls.pop_front();
        sz--;
    }
    // remove the element at back from queue
    void pop_back(){
        if(sz == 0)
            return;
    
        ls.pop_back();
        sz--;
    }
    // return element at front
    int front(){
        return ls.front();
    }
    // return element at end
    int rear(){
        return ls.back();
    }
    // to check that queue is empty or not
    bool empty(){
        return sz == 0;
    }
    // return size of queue
    int size(){
        return sz;
    }
};
int main() 
{
    Dequeue* my_dequeue = new Dequeue();

    cout << my_dequeue->empty() << endl; // it will print 1 because initilly dequeue is empty

    my_dequeue->push_back(1); // it will add 1 at the end of dequeue

    cout << my_dequeue->size() << endl; // size of dequeue

    cout << my_dequeue->front() << " " << my_dequeue->rear() << endl; // there is only one element so front and rear will be same

    // push some items at the end of dequeue
    my_dequeue->push_back(2);
    my_dequeue->push_back(3);
    my_dequeue->push_back(4);
    my_dequeue->push_back(5);
    // push some items at the front of dequeue
    my_dequeue->push_front(6);
    my_dequeue->push_front(7);
    my_dequeue->push_front(8);
    my_dequeue->push_front(9);
    
    cout << my_dequeue->size() << endl; // it will print 9

    cout << my_dequeue->front() << " " << my_dequeue->rear() << endl; // it will print 9 5
    
    // remove some items from the back of dequeue
    my_dequeue->pop_back();
    my_dequeue->pop_back();
    // remove some items from the front of dequeue
    my_dequeue->pop_front();
    my_dequeue->pop_front();

    cout << my_dequeue->size() << endl; // it will print 5

    cout << my_dequeue->front() << " " << my_dequeue->rear() << endl; // it will print 7 3
    
    return 0;
}
