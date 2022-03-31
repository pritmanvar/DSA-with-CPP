// Problem Link : https://codeforces.com/problemset/problem/1613/C
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    li h;
    cin >> n >> h;
    vector<li> a(n);
    
    for (li &x : a) cin >> x;
    
    li l = 1, r = 1e18;
    while (l <= r) {
      li m = (l + r) / 2;
      li sum = m;
      
      for (int i = 0; i < n - 1; ++i) 
        sum += min(m, a[i + 1] - a[i]);
      
      if (sum < h) l = m + 1;
      else r = m - 1;
    }
    cout << r + 1 << '\n';
  }
}
