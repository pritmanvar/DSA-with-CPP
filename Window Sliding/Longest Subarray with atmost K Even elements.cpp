// Problem Link : https://practice.geeksforgeeks.org/problems/longest-subarray-with-atmost-k-even-elements/0/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int st = 0;
        int ed = 0;
        int len = 0;
        int maxlen = 0;
        while(ed < n && k > 0){
            if(arr[ed] % 2 == 0)
                k--;
            len++;
            ed++;
        }
        if(ed == n){
            cout << n << endl;
            continue;
        }
        while(ed < n){
            while(ed < n && arr[ed]%2 == 1){
                len++;
                ed++;
            }
            maxlen = max(len,maxlen);
            if(ed < n && arr[ed]%2 == 0){
                while(st <= ed && arr[st]%2 != 0){
                    len--;
                    st++;
                }
                if(st <= ed && arr[st]%2 == 0){
                    st++;
                    ed++;
                }
            }
        }
        cout << maxlen << endl;
    }
	return 0;
}