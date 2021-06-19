// Problem Link : https://leetcode.com/problems/first-missing-positive/
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        
        for(int i = 0; i < n; i++){// adding every element in the set.
            st.insert(nums[i]);
        }
        
        int i = 1;
        while(st.find(i) != st.end()){ // starting from 1 and as we see that element is not present in the set we return that
            i++;
        }
        return i;
    }
