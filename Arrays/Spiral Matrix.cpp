// Problem Link : https://leetcode.com/problems/spiral-matrix/
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        
        if(r == 1){ // special case of 1 row
            for(int i = 0; i < c; i++){
                ans.push_back(matrix[0][i]);
            }
            return ans;
        }
        if(c == 1){ // special case of 1 coloum
            for(int i = 0; i < r; i++){
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }
        
        int right = 0;
        int bottom = c-1;
        int left = r-1;
        int top = 0;
        
        while(right <= left && top <= bottom){
            for(int i = top; i <= bottom; i++){ //to traverse left to right
                ans.push_back(matrix[right][i]);
            }
            right++;
            for(int i = right; i <= left; i++){ //to traverse top to bottom
                ans.push_back(matrix[i][bottom]);
            }
            bottom--;
            if(right <= left){
                for(int i = bottom; i >= top; i--){ //to traverse right to left
                    ans.push_back(matrix[left][i]);
                }
            }
            left--;
            if(top <= bottom){
                for(int i = left; i >= right; i--){ //to traverse bottom to top
                    ans.push_back(matrix[i][top]);
                }
            }
            top++;
        }
        
        return ans;
    }
