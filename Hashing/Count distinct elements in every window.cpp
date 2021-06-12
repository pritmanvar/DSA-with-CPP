// Problem Link : https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/?category[]=sliding-window&category[]=sliding-window&page=1&sortBy=submissions&query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 0; i<k; i++){ // Counting for the 1st window.
            mp[A[i]]++;
        }
        ans.push_back(mp.size());
        for(int i = 1; i <= n-k; i++){ // traversing other windoes with help of sliding window method.
            mp[A[i+k-1]]++;
            mp[A[i-1]]--;
            if(mp[A[i-1]] == 0){
                mp.erase(A[i-1]);
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
