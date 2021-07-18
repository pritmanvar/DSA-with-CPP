// Problem Link : https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/?track=P100-Stack&batchId=197#
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // I will store top half element in the another stack
        // after that i will remove top element of stack which will be mid element
        // then i will again add half elemens which are stored in another stack
        stack<int> temp;
        for(int i = 0; i < sizeOfStack/2; i++){
            temp.push(s.top());
            s.pop();
        }
        s.pop();
        for(int i = 0; i < sizeOfStack/2; i++){
            s.push(temp.top());
            temp.pop();
        }
    }
