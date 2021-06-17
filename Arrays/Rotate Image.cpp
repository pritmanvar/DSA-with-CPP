// Problem Link : https://leetcode.com/problems/rotate-image/
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){ // finding transpos of matrix
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++){ // reversing every row to rotate it
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
