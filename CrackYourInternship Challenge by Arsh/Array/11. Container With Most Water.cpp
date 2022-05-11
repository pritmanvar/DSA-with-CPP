// Problem Link : https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;
        while(i < j){
            ans = max(ans,(j-i)*min(height[j],height[i]));
            
            if(height[i] > height[j])
                j--;
            else if(height[i] < height[j])
                i++;
            else{
                if(height[i+1] > height[j-1])
                    i++;
                else
                    j--;
            }
        }
        return ans;
    }
};
