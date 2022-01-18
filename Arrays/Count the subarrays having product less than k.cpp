// Problem Link : https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long mul = 1;
        int ans = 0;
        int st = 0, ed = 0;
        
        
        while(ed < n){
            // valid window
            while(ed < n && mul*a[ed] < k){
                mul *= a[ed];
                ed++;
            }
            
            if(ed == st){ // corner case
                ed++,st++;
                continue;
            }
            ans += ed-st; // number of subarrays in this valid window who ends with ed.
            mul /= a[st];
            st++;
        }
        while(st < ed){ // reduce window.
            ans += ed-st;
            mul /= a[st];
            st++;
        }
        return ans;
    }
};
