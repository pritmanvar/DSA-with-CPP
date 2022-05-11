// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] - mn > 0){
                ans += prices[i] - mn;
                mn = INT_MAX;
            }
            mn = min(mn,prices[i]);
        }
        return ans;
    }
};
