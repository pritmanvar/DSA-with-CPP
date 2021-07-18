// Problem Link : https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
    int median(vector<vector<int>> &matrix, int r, int c){
        // our answer will be between 1 to 2000 because it is range of matrix
        // we can also find range by finding min and max value of matrix
        int l = 1;
        int h = 2000;
        
        while(l <= h){
            int m = (l+h)/2;
            
            int num = 0;
            // it will find number of elements which are less than m
            for(int i = 0; i < r; i++){
                num += upper_bound(matrix[i].begin(),matrix[i].end(),m) - matrix[i].begin();
            }
            
            // if number of elements who are less than mid are less than half elements then we can ignore left half
            if(num < (r*c + 1)/2){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return l;
    }
