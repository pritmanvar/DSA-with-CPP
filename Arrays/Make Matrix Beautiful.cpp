// Problem Link : https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1/?track=P100-Matrix&batchId=197
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> row(n); // in ith index we will store sum of ith row
        vector<int> coloumn(n); // in ith index we will store sum of ith coloumn
        
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            row[i] = accumulate(matrix[i].begin(),matrix[i].end(),0); // sum of current row
            mx = max(mx,row[i]); // finding max
            int sum = 0;
            for(int j = 0; j < n; j++){ // sum of current coloumn
                sum += matrix[j][i];
            }
            coloumn[i] = sum;
            mx = max(sum,mx);
        }
        int ans = 0;
        // we need to add 2*mx - row[i] - coloumn[i] to make row == coloumn
        for(int i = 0; i < n; i++){
            ans += 2*mx - row[i] - coloumn[i];
        }
        // each element is consideres 2 times to we will devide by 2
        return ans/2;
    } 
