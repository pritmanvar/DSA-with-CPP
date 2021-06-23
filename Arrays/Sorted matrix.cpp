// Problem Link : https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> temp;
        for(int i = 0; i < N; i++){ // converting 2D array to 1D array
            for(int j = 0; j < N; j++){
                temp.push_back(Mat[i][j]);
            }
        }
        sort(temp.begin(),temp.end()); // sorting the array
        int indx = 0;
        for(int i = 0; i < N; i++){ // converting 1D array to 2D array
            for(int j = 0; j < N; j++){
                Mat[i][j] = temp[indx];
                indx++;
            }
        }
        return Mat;
    }
