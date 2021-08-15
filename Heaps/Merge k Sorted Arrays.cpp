// Problem Link : https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#
    
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
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<storage, vector<storage>, compare> pq; // priority_queue of storage
        vector<int> ans; // vector to store answer
        
        // adding 1st element of every row into the prioriry queue
        for(int i = 0; i < k; i++){
            storage temp = {arr[i][0],i,0};
            pq.push(temp);
        }
        
        while(pq.size() != 0){
            storage next = pq.top(); // getting smallest element from priority queue
            pq.pop();
            ans.push_back(next.data); // adding that into answer
            // if it is not last element of that row then add its next element in the priority queue
            if(next.index+1 < k){
                storage temp = {arr[next.row][next.index+1], next.row, next.index+1};
                pq.push(temp);
            }
        }
        return ans; // return answer
    }
