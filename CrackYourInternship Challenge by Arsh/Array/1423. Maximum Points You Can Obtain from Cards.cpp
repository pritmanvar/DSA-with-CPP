// Problem Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), windowSize = n-k;
        int windowSum = 0, sum = 0;
        
        for(int i = 0; i < windowSize; i++){
            sum += cardPoints[i];
            windowSum += cardPoints[i];
        }
        int minSum = windowSum;
        for(int i = windowSize; i < n; i++){
            sum += cardPoints[i];
            windowSum += cardPoints[i] - cardPoints[i-windowSize];
            minSum = min(minSum,windowSum);
        }
        return sum - minSum;
    }
};
