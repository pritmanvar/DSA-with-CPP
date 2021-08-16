// Problem Link : https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
    long long minCost(long long arr[], long long n) {
        // declaring min priority queue and adding every element into priority queue
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr,arr+n); 

        long long int cost = 0;
        // I will pop 2 smallest element and connect them to make cost minimum
        // after that again add connected rope into priority queue
        while(pq.size() > 1){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            cost += first+second;
            pq.push(first+second);
        }
        return cost; // return answer
    }
