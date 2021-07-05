// Problem Link : https://leetcode.com/problems/search-a-2d-matrix/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Used simple binary search where i will convert 2d index into 1d to calculate mid,l and h
        // and to access elements i will convert 1d index into 2d index with help of '/' and '%'
        
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int h = n*m - 1;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            if(matrix[mid/m][mid%m] > target){
                h = mid-1;
            }else if(matrix[mid/m][mid%m] < target){
                l = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
