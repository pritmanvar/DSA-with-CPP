// Problem Link : https://leetcode.com/problems/product-of-array-except-self/submissions/
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){ 
            return nums;
        }
        vector<int> ans;
        vector<int> prefix(n); // to store prefix
        vector<int> sufix(n); // to store sufix
        
        prefix[0] = 1;
        prefix[1] = nums[0];
        sufix[n-1] = 1;
        sufix[n-2] = nums[n-1];
        
        for(int i = 2; i < n; i++){ // calculationg prefix
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i = n-3; i >= 0; i--){// calculationg sufix
            sufix[i] = sufix[i+1]*nums[i+1];
        }
        for(int i = 0; i < n; i++){
            ans.push_back(prefix[i]*sufix[i]);
        }
        
        return ans;
    }
