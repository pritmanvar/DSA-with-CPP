// Problem Link : https://leetcode.com/problems/largest-rectangle-in-histogram/
    int largestRectangleArea(vector<int> height) {
        int n = height.size();
        
        vector<int> left(n); // it will store the index of next smaller element on the left of it
        vector<int> right(n); // it will store the index of next smaller element on the right of it
        
        left[0] = -1; // there is no any element on the left of 1st element so marked it with -1
        right[n-1] = -1; // there is no any element on the right of last element so marked it with -1
        
        for(int i = 1; i < n; i++){
            if(height[i-1] < height[i]){ // if hight of previous element is smaller than this one then it is the next smaller index for this one
                left[i] = i-1;
            }else{
                int j = i-1;// we will start with i-1
                while(true){
                    if(height[j] < height[i]){ // if hight of jth element is smaller than this one then it is the next smaller index for this one
                        left[i] = j;
                        break;
                    }else if(left[j] == -1){ // jth element is larger than this but there is not any element which is smaller then jth. so there will not any element smaller than current one
                        left[i] = -1;
                        break;
                    }else{ // if non of above then we will check same for the smaller element than jth one
                        j = left[j];
                    }
                }
            }
        }
        
        // logic is same as left
        for(int i = n-2; i >= 0; i--){
            if(height[i+1] < height[i]){
                right[i] = i+1;
            }else{
                int j = i+1;
                while(true){
                    if(height[j] < height[i]){
                        right[i] = j;
                        break;
                    }else if(right[j] == -1){
                        right[i] = -1;
                        break;
                    }else{
                        j = right[j];
                    }
                }
            }
        }
        
        int answer = INT_MIN;
        
        for(int i = 0; i < n; i++){
            int r,l;
            // finding number of larger element than current one on the right side
            if(right[i] == -1){ 
                r = n-i-1;
            }else{
                r = right[i]-i-1;
            }
            // finding number of larger element than current one on the left side
            if(left[i] == -1){
                l = i;
            }else{
                l = i-left[i]-1;
            }
            answer = max(answer,(r+l+1)*height[i]);//updating answer if possible
        }
        return answer;
    }
