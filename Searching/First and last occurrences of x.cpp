// Problem Link : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

// Modified Binary Search
vector<int> find(int arr[], int n , int x )
{
    // code here
    int first;
    int last;
    
    int l = 0;
    int h = n-1;
    bool check = true;
    while(l <= h){
        int m = l + (h - l)/2;
        
        if(arr[m] > x){
            h = m-1;
        }else if(arr[m] < x){
            l = m+1;
        }else if(m == 0 || arr[m-1] != x){
            first = m;
            check = false;
            break;
        }else{
            h = m-1;
        }
    }
    if(check)
        first = -1;
    check = true;
    
    l = 0;//5
    h = n-1;//8,5
    while(l <= h){
        int m = l + (h - l)/2;//4,6
        // cout << arr[m] << " " << arr[m+1] << endl;
        if(arr[m] > x){
            h = m-1;
        }else if(arr[m] < x){
            l = m+1;
        }else if(m == n-1 || arr[m+1] != x){
            last = m;
            check = false;
            break;
        }else{
            l = m+1;
        }
    }
    if(check)
        last = -1;
        
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);
    
    return ans;
}