// Problem Link : https://codeforces.com/contest/1551/problem/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        // there is only two coins so i will devide it into 3 equal part
        // if n == 6 then i will devide it into 2,2,2
        // now one part will be for coin whose value is 1 and onther 2 parths is for another coin
        int one = n/3;
        int two = n/3;

        // if there is a reminder
        if(n%3 == 1){
            one++;
        }else if(n%3 == 2){
            two++;
        }
        
        cout << one << " " << two << endl;
    }
    return 0;
}
