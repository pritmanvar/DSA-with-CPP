//Problem Link : https://leetcode.com/problems/next-permutation/
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        //Traverse through an array from last to find the first decreasing element in array from last
        for(i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        int j;
        // Traverse through an array from last to find smallest element which is greater than first decreasing element
        for(j = n-1; j > i && i >= 0; j--){
            if(nums[j] > nums[i]){
                break;
            }
        }
        if(i >= 0)
            swap(nums[i],nums[j]);//Swap to both to get greater greater permutation
        reverse(nums.begin()+i+1,nums.end());
    }
