// Problem Link : https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> ans;
        
        long long int mull = 1;
        int zeros = 0; // number of zeros in the nums
        
        // we will find multiplication of non-zero elements
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeros++;
                continue;
            }
            mull *= nums[i];
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                // if number is non-zero and there is any zero in nums then ans of this will 0 else mull/nums[i]
                if(zeros > 0)
                    ans.push_back(0);
                else
                    ans.push_back(mull/nums[i]);
            }else if(nums[i] == 0){
                // if current one is zero and there is only 1 zero then ans will be mull else 0
                if(zeros == 1)
                    ans.push_back(mull);
                else
                    ans.push_back(0);
            }
        }
        
        return ans;
    }
