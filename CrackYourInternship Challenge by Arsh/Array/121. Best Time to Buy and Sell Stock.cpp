// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, n = prices.size();
        int max_profit = 0;
        
        for(int i = 0; i < n; i++){
            mn = min(mn,prices[i]);
            max_profit = max(max_profit,prices[i]-mn);
        }
        return max_profit;
    }
};
