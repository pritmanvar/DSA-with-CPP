// Problem Link : https://leetcode.com/problems/search-a-2d-matrix-ii/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // I will start from top right corner
        int i = 0, j = matrix[0].size()-1;
        
        while(i < matrix.size() && j >= 0){
            
            if(matrix[i][j] > target) // if current element is greater then elements below it will also larger so we can skip that by j--
                j--;
            else if(matrix[i][j] < target) // if current element is smaller then element before it will also smaller so we can skip that by i++
                i++;
            else // if element is same then return true
                return true;
        }
        return false;
    }
