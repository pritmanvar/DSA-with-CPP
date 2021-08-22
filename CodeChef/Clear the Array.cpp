// Problem Link : https://www.codechef.com/COOK132B/problems/CLEARARR
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k,x;
        cin >> n >> k >> x;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        // sort array in nod increasing order
        // because of this first i will always try to remove 2 element in one move whose value is larges in the array
        sort(arr,arr+n,greater<int>()); 
        long long int ans = 0;
        int i = 0;
        while(i+1 < n && k > 0){ // while my k is greater than 0 i wll check that can i remove both left and right element in one move or not
            if(arr[i]+arr[i+1] >= x){ // if remove both element in one move has low cost then i will remove that 
                ans += x;
                k--;
                i += 2;
            }else{ // it individual cost is less then element after this has also less cost in individual so no meaning to run loop ahead 
                break;
            }
        }
        while(i < n){ // removing every element which are present 
            ans += arr[i];
            i++;
        }
        cout << ans << endl; // print the answer
    }
    return 0;
}
