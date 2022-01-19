// Problem Link : https://www.codechef.com/START22B/problems/EVENXOR
// if number x is not bad then it will be present in the special array

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        long long int temp = 0;
        while(n > 0){
            if(__builtin_popcount(temp)%2 == 0){ // this function will return number of set digits in integer.
                cout << temp << " ";
                n--;
            }
            temp++;
        }
        cout << endl;
    }
    return 0;
}
