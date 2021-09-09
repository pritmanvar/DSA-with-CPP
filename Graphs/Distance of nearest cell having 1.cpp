// Problem Link : https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
    void fill(vector<vector<int>>& grid, vector<vector<int>>& answer, int n, int m, int row, int col){
        for(int i = 1; i < n+m; i++){ // maximum distance can be n+m
            // it will check is there any 1 in 1st quadrant with distance i
            int x = col;
            int y = row-i;
            while(y <= row){
                if(y >= 0 && x < m){
                    if(grid[y][x] == 1){ // if there is 1 then put distance in answer and return
                        answer[row][col] = i;
                        return;
                    }
                }
                y++;
                x++;
            }
            // it will check is there any 1 in 4th quadrant with distance i
            y = row;
            x = col+i;
            while(x >= col){
                if(y < n && x < m){
                    if(grid[y][x] == 1){ // if there is 1 then put distance in answer and return
                        answer[row][col] = i;
                        return;
                    }
                }
                y++;
                x--;
            }
            // it will check is there any 1 in 3rd quadrant with distance i
            y = row+i;
            x = col;
            while(y >= row){
                if(y < n && x >= 0){
                    if(grid[y][x] == 1){ // if there is 1 then put distance in answer and return
                        answer[row][col] = i;
                        return;
                    }
                }
                y--;
                x--;
            }
            // it will check is there any 1 in 2nd quadrant with distance i
            y = row;
            x = col-i;
            while(x <= col){
                if(x >= 0 && y >= 0){
                    if(grid[y][x] == 1){ // if there is 1 then put distance in answer and return
                        answer[row][col] = i;
                        return;
                    }
                }
                x++;
                y--;
            }
        }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(); // number of rows in grid
	    int m = grid[0].size(); // number of coloumns in grid
	    
	    vector<vector<int>> answer(n, vector<int>(m)); // to store output grid
	    // traverse through grid
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j] == 1){ // if value at this cell in grid is 1 then its distance will be 0
	                answer[i][j] = 0;
	            }else{ // else i will call for fill function
	                fill(grid,answer,n,m,i,j);
	            }
	        }
	    }
	    return answer;
	}
