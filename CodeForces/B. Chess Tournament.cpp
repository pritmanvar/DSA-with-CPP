// Problem Link : https://codeforces.com/contest/1569/problem/B
 
// Approch : This approch is taken from codeforces tutorial.
// Since the chess players of the first type should not lose a single game, 
// each game between two chess players of the first type should end in a draw (so that none of them gets defeated). 
// And a game between a chess player of the first type and the second type should end either with a victory of the first or a draw. 
// Therefore, for convenience, we will say that all games with a chess player of the first type end in a draw.

// Now there are only games between chess players of the second type left. If there are only 1 or 2 such players, then there is no answer. 
// Otherwise, we can choose the following method: 
// the i-th chess player of the second type wins against the i+1-th chess player of the second type, and the last one wins against the first; all remaining games are drawn.


#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        string str;
        cin >> str;

        vector<vector<char>> ans(n, vector<char>(n,'=')); // fill all cells with '='
        vector<int> twos;

        // finding index of '2' and fill diagonal entries with 'X'
        for(int i = 0; i < n; i++){
            ans[i][i] = 'X';
            if(str[i] == '2')
                twos.push_back(i);
        }
        int sz = twos.size();
        if(sz == 1 || sz == 2){ // if number of '2' is one or two then answer will be NO
            cout << "NO\n";
            continue;
        }
        // cell at which both players has choce 2. I will declare winner to ith player agains (i+1)th player.
        // last player will win agains first player.
        for(int i = 0; i < sz; i++){
            int next = (i+1)%sz;
            ans[twos[i]][twos[next]] = '+';
            ans[twos[next]][twos[i]] = '-';
        }
        // print answer.
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
