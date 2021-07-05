// Problem Link : https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1/?track=P100-Matrix&batchId=197#
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<bool> row(r); // if there is any 1 in the ith row then ith index of this vector will be true
        vector<bool> coloumn(c); // if there is any 1 in the ith coloumn then ith index of this vector will be true
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                // updating row and coloumn vector if there is one
                if(matrix[i][j] == 1){
                    row[i] = true;
                    coloumn[j] = true;
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                // if there is any 1 in current coloumn and row then make current element 1
                if(row[i] == true || coloumn[j] == true){
                    matrix[i][j] = 1;
                }
            }
        }
    }
