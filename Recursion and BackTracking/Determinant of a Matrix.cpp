// Problem Link : https://practice.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1/?track=P100-Matrix&batchId=197#
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // if matrix is 1x1 then determinatnt of that will be that cell
        if(n == 1){
            return matrix[0][0];
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            vector<vector<int>> temp; // new matrix in which we will remove 0th row and ith coloumn
            for(int j = 1; j < n; j++){
                temp.push_back(matrix[j]);
                temp[j-1].erase(temp[j-1].begin()+i);
            }
            // general equation to find determinant of matrix
            // cramer's rule
            ans += matrix[0][i]*pow(-1,i)*determinantOfMatrix(temp,n-1);
        }
        return ans;
    }
