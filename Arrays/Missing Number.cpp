// Problem Link : https://leetcode.com/problems/missing-number/submissions/
    int missingNumber(vector<int>& nums) {  
        int ans = 0; 
        int n = nums.size();
        for(int i = 1; i <= n; i++){
            ans ^= i; // it will take xor of 1 to n
            if(nums[i-1] != 0)
                ans ^= nums[i-1]; // it will take xor of every element of array
        }
        // accordint to xor property a^a == 0
        // duplicates elements will cancel out so at last ans will contain missing element
        
        return ans;
    }
