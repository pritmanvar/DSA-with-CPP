// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1){ // if n == 1 then we can't get any profit
            return 0;
        }
        int max_profit = INT_MIN;
        int profit = 0; 
        int buy = prices[0]; // intilly we will but at 1st day
        
        for(int i = 0; i < n-1; i++){
            if(buy > prices[i]){ // if price of current day is less than the day when we bought then we weill buy stock at this day and make profit 0
                buy = prices[i];
                profit = 0;
            }
            
            if(prices[i+1] < prices[i]){ // if next day price is less than current one then we will collect profit
                max_profit = max(max_profit,profit);
            }
            profit += prices[i+1]-prices[i]; // updating profit by next day
        }
        return max_profit = max(max_profit,profit);
    }
