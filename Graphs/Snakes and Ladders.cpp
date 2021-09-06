// Problem Link : https://leetcode.com/problems/snakes-and-ladders/
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(); 
        // graph to represent board
        // I am using set to avoid duplicates
        vector<unordered_set<int>> graph(n*n+1); 
        
        for(int i = 1; i <= n*n; i++){
            // from ith num i can go to 6th  cell ahead so i will run a loop for that
            for(int j = 1; j <= 6 && i+j <= n*n; j++){
                int r1 = (i+j-1)/n; // convert number to row number
                int c1 = (i+j-1)%n; // convert number to coloumn number

                // index are considered to bottom lect corner so convert row and coloumn accordingly 
                if(r1%2 == 1){
                    c1 = n-1-c1;
                }
                r1 = n-1-r1;
                // if current cell has snake or ladder then i will insert its destination else i will add current number
                if(board[r1][c1] != -1){
                    graph[i].insert(board[r1][c1]);
                }else{
                    graph[i].insert(i+j);
                }
            }
        }
        int steps = 1; // to count steps
        vector<bool> visited(n*n+1); // to mark visited cells 
        queue<int> q; // queue for BFS
        
        // BFS
        q.push(1);
        visited[1] = true;
        while(q.empty() == false){
            int count = q.size();
            for(int i = 0; i < count; i++){
                int temp = q.front();
                q.pop();
                
                for(auto next : graph[temp]){
                    if(next == n*n){ // if current cell is destination then retuen steps
                        return steps;
                    }
                    if(visited[next] == false){ // if current is not visited then add that into queue
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            steps++; // increment step
        }
        return -1; // if i can't reach to destination then i will return -1
    }
