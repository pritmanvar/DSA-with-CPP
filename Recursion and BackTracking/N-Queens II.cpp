// Problem Link : https://leetcode.com/problems/n-queens-ii/description/
    // solver function
    int solve(int n, int r, int coloum, int dia, int rdia){
        if(r == n){ // r ==n then add this possibilites in our answer
            return 1;
        }
        
        int answer = 0; // to store number of possible ways
        for(int i = 0; i < n; i++){ // try to put the queen for every coloum of this row.
            // checking that is there any queen on current coloum or any diagonal
            int check_coloum = 1 << i; // to check in coloum we will make a number in which only bit at ith position will be set
            int check_rdia = 1 << i+r; // to check in reverse diagonal we will make a number in which only bit at (i+r)th position will be set
            int check_dia = 1 << n-r+i-1; // to check in diagonal we will make a number in which only bit at (n-r+i+1)th position will be set
            
            // we are checkig that at the current diagonal or reverse diagonal or coloum there is queen or not.
            // if there is no queen than bit at corresponding position will be zero and in our check veriable bit at that possision will one so and of both will gove 0.
            // it shows that that position is safe.
            if((coloum&check_coloum) == 0 && (dia&check_dia) == 0 && (rdia&check_rdia) == 0){ 
                // we will set the bit at corresponding because we are going to put queen at this position.
                coloum |= check_coloum;
                rdia |= check_rdia;
                dia |= check_dia;
                answer += solve(n,r+1,coloum,dia,rdia);
                // backtracking
                // making bit at curresponding position as 0 because of backtracking purpose
                coloum ^= check_coloum;
                rdia ^= check_rdia;
                dia ^= check_dia;
            }
        }
        return answer;
    }
    
    int totalNQueens(int n) {
        int coloum = 0; // to store is there any queen present in the culoum in current possibility
        int dia = 0; // to store is there any queen present in the main diagonal in current possibility
        int rdia = 0; // to store is there any queen present in the other diagonal in current possibility
        
        return solve(n,0,coloum,dia,rdia); // calling for solution
    }
