// Problem Link : https://leetcode.com/problems/n-queens/
    vector<vector<string>> answer; // we will store our answer in this.
public:
    // to check that we can put queen at that place or not
    bool check(int r, int c, vector<string> arr){
        for(int i = 0; i <= r; i++){ // chacking that is there any queen in this row
            if(arr[i][c] == 'Q'){ // if there is queen then return false
                return false;
            }
        }
        for(int i = 0; i < r; i++){ // checking that is there any queen in the diagonal
            if(r-1-i >= 0 && c+1+i < arr.size() && arr[r-1-i][c+1+i] == 'Q'){ // if there is queen then return false
                return false;
            }
        }
        for(int i = 0; i < r; i++){ // checking that is there any queen in the other diagonal
            if(r-1-i >= 0 && c-1-i >= 0 && arr[r-1-i][c-1-i] == 'Q'){ // if there is queen then return false
                return false;
            }
        }
        return true;
    }
    
    // recursive function to solve problem
    void solve(int n, int r, vector<string> pos){
        if(r == n){ // r ==n then add this possibilites in our answer
            answer.push_back(pos);
            return;
        }
        
        for(int i = 0; i < n; i++){ // checking possibility for every coloum of this row.
            if(check(r,i,pos)){
                pos[r][i] = 'Q'; // putting queen on that index
                solve(n,r+1,pos);
                pos[r][i] = '.'; // backtracking
            }
        }
    }

    // main function
    vector<vector<string>> solveNQueens(int n) {
        string str = "";
        for(int i = 0; i < n; i++){
            str += '.';
        }
        vector<string> pos;
        // Initilizing vector as with "...."
        for(int i = 0; i < n; i++){
            pos.push_back(str);
        }
        
        solve(n,0,pos); // calling for solution
        return answer;
    }
