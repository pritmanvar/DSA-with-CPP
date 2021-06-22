// Problem Link : https://leetcode.com/problems/set-matrix-zeroes/submissions/
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        unordered_set<int> row;
        unordered_set<int> coloumn;
        
        // geting rows and coloumn which contains 0
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    coloumn.insert(j);
                }
            }
        }
        
        // setting 0 at the element is its row or coloumn contains 0
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(row.count(i) == 1 || coloumn.count(j) == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
