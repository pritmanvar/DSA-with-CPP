// Problem Link : https://www.codechef.com/START5C/problems/CHEFQUER
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    long long int arr[n];
    for (int i = 0; i < n; i++) // taking array
    {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++) // running loop for every query
    {
        int a;
        cin >> a; // taking 1st int
        if (a == 1) // If a == 1 then we have to edit the array
        {
            long long int l, r, x;
            cin >> l >> r >> x;

            for (int j = l - 1; j < r; j++) // editing the array as per given instructions
            {
                arr[j] += (x + j + 1 - l) * (x + j + 1 - l);
            }
        }
        else
        {
            int b;
            cin >> b;
            cout << arr[b - 1] << endl; // if a == 2 then we will print element at bth position
        }
    }
    return 0;
}
