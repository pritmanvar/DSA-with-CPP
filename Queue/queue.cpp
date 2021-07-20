#include<bits/stdc++.h>

using namespace std;
struct Queue{
    list<int> ls; // linkedlist to build a queue
    int sz;
    Queue(){
        sz = 0;
    }

    // add x at the end of queue
    void push(int x){
        sz++;
        ls.push_back(x);
    }
    // remove the element at front from queue
    void pop(){
        if(sz == 0)
            return;
    
        ls.pop_front();
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
    Queue* my_queue = new Queue();

    cout << my_queue->empty() << endl; // it will print 1 because initilly queue is empty

    my_queue->push(1); // it will add 1 at the end of queue

    cout << my_queue->size() << endl; // size of queue

    cout << my_queue->front() << " " << my_queue->rear() << endl; // there is only one element so front and rear will be same

    // push some items at the end of queue
    my_queue->push(2);
    my_queue->push(3);
    my_queue->push(4);
    my_queue->push(5);
    my_queue->push(6);
    my_queue->push(7);
    my_queue->push(8);
    my_queue->push(9);
    
    cout << my_queue->size() << endl; // it will print 9

    cout << my_queue->front() << " " << my_queue->rear() << endl; // it will print 1 9
    
    // remove some items from the front of queue
    my_queue->pop();
    my_queue->pop();
    my_queue->pop();
    my_queue->pop();

    cout << my_queue->size() << endl; // it will print 5

    cout << my_queue->front() << " " << my_queue->rear() << endl; // it will print 5 9
    return 0;
}
