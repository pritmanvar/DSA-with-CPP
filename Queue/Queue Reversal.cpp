// Problem Link : https://practice.geeksforgeeks.org/problems/queue-reversal/1#
queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    // adding all element into stack
    while(q.size()>0){
        s.push(q.front());
        q.pop();
    }
    // stack follows LIFO order so now i will move all elements from stack to queue to get reversed stack
    while(s.size() > 0){
        q.push(s.top());
        s.pop();
    }
    return q;
}
