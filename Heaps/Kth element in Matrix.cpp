// Problem Link : https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

// structure to store data
// row number in which data is stored
// index in row where data is stored
struct storage{
    int data;
    int row;
    int index;
        
    storage(int a, int b, int c){
        data = a;
        row = b;
        index = c;
    }
};
// comparator function for priority_queue
struct compare {
    bool operator()(storage s1, storage s2){
        return s1.data > s2.data;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k){
    priority_queue<storage, vector<storage>, compare> pq; // priority_queue of storage
        
    // adding 1st element of every row into the prioriry queue
    for(int i = 0; i < n; i++){
        storage temp = {mat[i][0],i,0};
        pq.push(temp);
    }
        
    int count = 0; // to store how many elements we have poped
    while(pq.size() != 0){
        // if we have removed k-1 small elements from priority queue 
        // then top element in priority queue must be kth smallest elements so i will return that
        if(count == k-1){ 
            return pq.top().data;
        }
        
        storage next = pq.top(); // getting smallest element from priority queue
        pq.pop();
        count++; // incrementing count because we are removing 1 smallest element from priorityqueue
        
        // if it is not last element of that row then add its next element in the priority queue
        if(next.index+1 < n){
            storage temp = {mat[next.row][next.index+1], next.row, next.index+1};
            pq.push(temp);
        }
    }
    return -1; // contril will never come here
}
