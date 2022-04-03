// Problem Link : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int r,c;
        cin >> r >> c;

        cout << "Case #" << z << ":\n";
        for(int i = 0; i < 2*r + 1; i++){
            for(int j = 0; j < 2*c + 1; j++){
                if(i < 2 && j < 2){
                    cout << '.';
                }else if(i%2 == 0){
                    if(j%2 == 0)
                        cout << '+';
                    else
                        cout << '-';
                }else{
                    if(j%2 == 0)
                        cout << '|';
                    else
                        cout << '.';
                }
            }
            cout << endl;
        }
    }
    return 0;
}
