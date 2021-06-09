// Problem Link : https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
    int getPairsCount(int arr[], int n, int k) {
        // we will maintain count thai which elements appears how many times before current position
        // so for current element our required element would be k - arr[i] 
        // so we will increment answer by count of k-arr[i] 
        // because current element can make a pair with all element which are equal to k-arr[i]
        int answer = 0;
        unordered_map<int,int> track; 
        for(int i = 0; i < n; i++){
            answer += track[k - arr[i]];
            track[arr[i]]++;
        }
        return answer;
    }
