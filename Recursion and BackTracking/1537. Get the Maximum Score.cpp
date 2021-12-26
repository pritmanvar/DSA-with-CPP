// Problem Link : https://leetcode.com/problems/get-the-maximum-score/

/****************************Intuition*****************************

I have to take all elements from array till i didn't find same element in another array.
because i can move to another array if and only if there is same element in both.

so if i suppose element at index 'i' and 'j' are present in another array and elements between 'i' and 'j' are not present then i will consider elements from 'i+1' to 'j' as single block and i have to find max sum using this array of blocks.



********************************Approch******************************
1. i will count sum of every block and store that in another vector. I will do this for the both vector which are given.

2. i have to find max score using this new arrays. and at every point i have 2 choices i can take element from array1 or array2. but to get max score i will take element which is larger.

*/
class Solution {
private:
    int N = 1000000007;
    int getMaxSum(vector<long long>& arr1, vector<long long>& arr2, int n){
        if(n == 0)
            return 0;
        
        long long sum = getMaxSum(arr1,arr2,n-1);
        
        // at this point i have 2 choice 
        // i can take element from arr1 or arr2 and i will take larger element from it.
        sum = (sum + max(arr1[n-1],arr2[n-1]))%N;
        
        return sum;
    }
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<long long> arr1, arr2; // to store sum of blocks
        long long sum1 = 0, sum2 = 0; // sum of current block
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        
        while(i < n1 && j < n2){
            // if at this point element is present in both array then it is end of the block so add sum into arrays and reset the sum.
            
            // elese i will go to the next element in the array with smaller element to get next same element.
            if(nums1[i] == nums2[j]){ 
                sum1 = (sum1+nums1[i]);
                sum2 = (sum2+nums2[j]);
                
                arr1.push_back(sum1);
                arr2.push_back(sum2);
                sum1 = sum2 = 0;
                
                i++,j++;
            }else if(nums1[i] < nums2[j]){
                sum1 = (sum1+nums1[i]);
                i++;
            }else{
                sum2 = (sum2+nums2[j]);
                j++;
            }
        }
        while(i < n1){
            sum1 = (sum1+nums1[i]);
            i++;
        }
        while(j < n2){
            sum2 = (sum2+nums2[j]);
            j++;
        }
        arr1.push_back(sum1);
        arr2.push_back(sum2);
        
        return getMaxSum(arr1,arr2,arr1.size()); // to get max score.
    }
};
