// Problem Link : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b

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
        int c1[4], c2[4], c3[4];

        cin >> c1[0] >> c1[1] >> c1[2] >> c1[3];
        cin >> c2[0] >> c2[1] >> c2[2] >> c2[3];
        cin >> c3[0] >> c3[1] >> c3[2] >> c3[3];

        int a = min(c1[0], min(c2[0],c3[0]));
        int b = min(c1[1], min(c2[1],c3[1]));
        int c = min(c1[2], min(c2[2],c3[2]));
        int d = min(c1[3], min(c2[3],c3[3]));
        // cout << a+b+c+d << endl;

        if((a + b + c + d) < 1000000){
            cout << "Case #" << z << ": " << "IMPOSSIBLE" << endl;
        }else{
            int need = 1000000;
            cout << "Case #" << z << ": ";
            if(need >= a){
                cout << a << " ";
                need -= a;
            }else{
                cout << need << " ";
                need = 0;
            }

            if(need >= b){
                cout << b << " ";
                need -= b;
            }else{
                cout << need << " ";
                need = 0;
            }

            if(need >= c){
                cout << c << " ";
                need -= c;
            }else{
                cout << need << " ";
                need = 0;
            }

            if(need >= d){
                cout << d << " ";
                need -= d;
            }else{
                cout << need << " ";
                need = 0;
            }
            cout << endl;
        }
    }
    return 0;
}
