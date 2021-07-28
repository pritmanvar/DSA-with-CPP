// Problem Link : https://www.codechef.com/COOK131B/problems/CHFGCD

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int x,y;
        cin >> x >> y;

        if(__gcd(x,y) > 1){ // if GCD of both is > 1 then answer is 0
            cout << 0 << endl;
        }else if((x%2 == 0 && y%2 == 1) || (x%2 == 1 && y&2 == 0)){ // if one of them is odd then we can increment that so now both can be devided ny 2
            cout << 1 << endl;
        }else if(__gcd(x+1,y) > 1 || __gcd(x,y+1) > 1){ // if we increment one and it's GCD becomes greater then one
            cout << 1 << endl;
        }else{ // if both are odd then i will increment both and make them even
            cout << 2 << endl;
        }
    }
    return 0;
}
