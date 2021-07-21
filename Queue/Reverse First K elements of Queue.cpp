// Problem Link : https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> store_k; // to store 1st k elements
    queue<int> ans; // to store answer
    int n = q.size(); // number of elements in the queue
    
    // moving 1st k elements into stack because we have to reverse 1st k elements
    for(int i = 0; i < k; i++){
        store_k.push(q.front());
        q.pop();
        
    }
    for(int i = 0; i < n; i++){
        // moving 1st k elements from stack to ans 
        // stack follows LIFO order so it will reversed
        if(i < k){
            ans.push(store_k.top());
            store_k.pop();
        }else{ // we have not to do anything with other element so i will simply copy that from q to ans
            ans.push(q.front());
            q.pop();
        }
    }
    return ans;
}
