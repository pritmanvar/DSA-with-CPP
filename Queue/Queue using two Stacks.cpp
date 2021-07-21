/* Problem Link : https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
};*/

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x); // simply push element in 1st stack
}
//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    // corner case
    if(s1.empty())
        return -1;
    
    // move all elements in 2nd stack except 1sst element
    while(s1.size() > 1){
        s2.push(s1.top());
        s1.pop();
    }
    // pop 1st element
    int poped = s1.top();
    s1.pop();
    // again move all elements in 1st stack
    while(s2.size() > 0){
        s1.push(s2.top());
        s2.pop();
    }
    return poped;
}
