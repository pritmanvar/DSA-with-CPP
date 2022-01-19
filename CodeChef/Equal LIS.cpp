// Problem Link : https://www.codechef.com/START22B/problems/EQLIS

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

        if(n == 2){
            cout << "NO\n";
        }else{
            cout << "YES\n";

            int arr[n];
            int temp = 1;

            int pos = 0;
            for(int i = 0; i < n/2; i++){
                arr[pos] = temp;
                pos++;
                temp += 2;
            }
            if(n%2 == 1){
                arr[pos] = n;
                pos++;
            }
            temp = n/2*2;
            for(int i = 0; i < n/2; i++){
                arr[pos] = temp;
                pos++;
                temp -= 2;
            }
            if(n%2 == 0){
                swap(arr[0],arr[1]);
            }
            for(int i = 0; i < n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
