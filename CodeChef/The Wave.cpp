// Problem Link : https://www.codechef.com/COOK130C/problems/WAV2
#include <bits/stdc++.h>

using namespace std;
// binary search
// it will return index of required element if it is present
// else return index of just larger element than required element
int bsearch(int arr[], int n, int x) 
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] > x)
        {
            e = m - 1;
        }
        else if (arr[m] < x)
        {
            s = m + 1;
        }
        else
        {
            return m;
        }
    }
    return s;
}
int main()
{

    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n); // sorting aray for binary search

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int indx = bsearch(arr, n, x);
        if (arr[indx] == x) // if element is present then we will print 0 beccause one element will be 0 so all multiplication will be 0
        {
            cout << 0 << endl;
        }
        else
        {
            int mx = n - indx;
            if (mx % 2 == 0) // number of larger element is even meanse there will be even number of negative number so multiplivation will be positive
            {
                cout << "POSITIVE\n";
            }
            else // number of larger element is odd meanse there will be odd number of negative number so multiplivation will be negative
            {
                cout << "NEGATIVE\n";
            }
        }
    }
    return 0;
}
