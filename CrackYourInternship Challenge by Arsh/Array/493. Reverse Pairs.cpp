// Problem Link : https://leetcode.com/problems/reverse-pairs/
class Solution {
private:
    int merge(vector<int>& nums, int st, int m, int ed){
        int ans = 0;
        
        // copy elements in array 1 and array 2 to merge
        vector<int> arr1, arr2;
        for(int i = st; i <= m; i++)
            arr1.push_back(nums[i]);
        for(int i = m+1; i <= ed; i++)
            arr2.push_back(nums[i]);
        
        
        // to calculate answer.
        int i = st, j = m+1;
        // elements in array 2 will be after every element in array 1 in original array.
        // calculate valid pairs between array 1 and array 2
        while(i <= m && j <= ed){
            if((long)nums[i] > 2*(long)nums[j]){
                ans += m-i+1; // if ith element is valid then every element after i is also valid
                j++;
            }else{
                i++;
            }
        }
        
        // actual merge function
        i = 0, j = 0;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] <= arr2[j])
                nums[st++] = arr1[i++];
            else
                nums[st++] = arr2[j++];
        }
        while(i < arr1.size())
            nums[st++] = arr1[i++];
        while(j < arr2.size())
            nums[st++] = arr2[j++];
        
        return ans;
    }
    int mergeSort(vector<int>& nums, int st, int ed){
        if(st == ed)
            return 0;
        
        int ans = 0, m = st + (ed-st)/2;
        ans += mergeSort(nums, st, m);
        ans += mergeSort(nums, m+1, ed);
        ans += merge(nums, st, m, ed);
        
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
