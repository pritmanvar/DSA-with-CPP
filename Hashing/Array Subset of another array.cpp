// Problem Link : https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
string isSubset(int a1[], int a2[], int n, int m) {
    if(m > n){
        return "No";
    }
    unordered_set<int> set1;
    for(int i = 0; i < n; i++){
        set1.insert(a1[i]);
    }
    for(int i = 0; i < m; i++){
        if(set1.count(a2[i]) == 0){
            return "No";
        }
    }
    return "Yes";
}
