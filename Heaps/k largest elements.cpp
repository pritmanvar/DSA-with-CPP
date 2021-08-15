// Problem Link : https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1#
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> pq; // declaring priority queue
	    
	    // adding every element into priority queue
	    for(int i = 0; i < n; i++){
	        pq.push(arr[i]);
	    }
	    vector<int> ans; // declaring answer
	    // adding k larger elements into ans
	    for(int i = 0; i < k; i++){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    return ans; // return ans
	}
