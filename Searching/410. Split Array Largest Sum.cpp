// Problem Link : https://leetcode.com/problems/split-array-largest-sum/
class Solution {
private:
    // this function will check that can we create exactly m groups if largest element in each group is limit.
    bool isValid(vector<int>& nums, int limit, int m){ 
        int sum = 0, count = 1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > limit) // current element doesn't fit into limit
                return false;
            
            if(nums.size()-i == m-count){ // number of remaining elements are same as required groups
                count++;
                sum = nums[i];
            }else if(sum + nums[i] <= limit){ // we can add current element in current group
                sum += nums[i];
            }else{
                count++;
                sum = nums[i];
            }
        }

        if(count == m)
            return true;
        else
            return false;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        int l = 0, h = accumulate(nums.begin(), nums.end(), 0); // range of binary search
        int ans = -1;
        
        while(l <= h){
            int mid = l + (h-l)/2;
            
            if(isValid(nums, mid, m)){ // if current largest element is valid then we will try to minimize that
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
