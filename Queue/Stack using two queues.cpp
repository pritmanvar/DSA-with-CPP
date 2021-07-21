/* Problem Link : https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#

The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};*/

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    // moving all elements from q1 to q2
    while(q1.size() > 0){
        q2.push(q1.front());
        q1.pop();
    }
    // add element in q1
    q1.push(x);
    // again moving all elements from q2 to q1
    while(q2.size() > 0){
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    // corner case
    if(q1.empty()){
        return -1;
    }
    // we had  added new element at front so i will pop element from front
    int poped = q1.front();
    q1.pop();
    return poped;
}
