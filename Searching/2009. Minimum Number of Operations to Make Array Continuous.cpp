// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
class Solution {
public:
    // Binary Search
    // it will give index of target and if target is not present then it will give largest element which is smaller than target
    int bsearch(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            
            if(target == nums[m])
                return m;
            else if(target < nums[m])
                h = m-1;
            else
                l = m+1;
        }
        return h;
    }
    int minOperations(vector<int>& nums) {
        // To remove duplicates
        unordered_set<int> st;
        int duplicates = 0;
        for(int i = 0; i < nums.size(); i++){
            if(st.count(nums[i]) == 0){
                st.insert(nums[i]);
            }else{
                nums[i] = -1;
                duplicates++;
            }
        }
        int ans = nums.size();
        
        // sort an array
        sort(nums.begin(), nums.end());
        
        for(int i = duplicates; i < nums.size(); i++){
            int valid = nums[i]+nums.size()-1; // this will be largest valid number if we start from nums[i]
            
            int indx = bsearch(nums,valid); // index of largest valid number
            int valid_numbers = indx-i+1; // numbers which are valid
            ans = min(ans,(int)nums.size()-valid_numbers); // substract valid numbers from total numbers to get valid numbers.
        }
        return ans;
    }
};
