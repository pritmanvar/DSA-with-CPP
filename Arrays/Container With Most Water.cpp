// Problem Link : https://leetcode.com/problems/container-with-most-water/submissions/
    int maxArea(vector<int>& height) {
        int n = height.size();
        // we will use 2 pointer algorithm 
        int start = 0;
        int end = n-1;
        int answer = 0;
        
        while(start < end){
            answer = max(answer,(end-start)*min(height[start],height[end])); // updating our answer
            
            // we will leave the element which is samller
            if(height[start] < height[end]){ 
                start++;
            }else if(height[start] > height[end]){
                end--;
            }else{
                // if both are same then we will go to the element which is larger
                if(start+1 < n && end-1 >= 0){
                    if(height[start+1] > height[end-1]){
                        start++;
                    }else{
                        end--;
                    }
                }
            }
        }
        return answer;
    }
