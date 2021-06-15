// Problem Link : https://practice.geeksforgeeks.org/problems/equivalent-sub-arrays3731/1/?category[]=sliding-window&amp;category[]=sliding-window&amp;page=1&amp;sortBy=submissions&amp;query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        int ans = 0;
        unordered_set<int> s1; // to count distinct elements in the array
        unordered_map<int,int> m2; // to count distinct elements in the window
        
        for(int i = 0; i < n; i++){
            s1.insert(arr[i]);
        }
        
        int i = 0;
        int j = 0;
        
        while(j < n){
            if(m2.size() < s1.size()){ // if window doesn't contain all distinct element then we will increase window
                m2[arr[j]]++;
                j++;
            }else{ // if windoww contain all distinct elements then we will add all possible subarraya to answer and remove 1st element of window
                ans += n-j+1;
                m2[arr[i]]--;
                if(m2[arr[i]] == 0){ // if current element is not present in the window then we will remove that from our map
                    m2.erase(arr[i]);
                }
                i++;
            }
        }
        while(m2.size() >= s1.size()){ // if j is at the end of array but till we can remove some elements from present window
                ans += n-j+1;
                m2[arr[i]]--;
                if(m2[arr[i]] == 0){
                    m2.erase(arr[i]);
                }
                i++;
        }
        return ans;
    }
