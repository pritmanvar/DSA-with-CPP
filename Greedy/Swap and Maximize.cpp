// Problem Link : https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1#

// i will put large element between 2 small elements.
long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n); // sort array in increasing order.
    int st = 0; // to point start
    int ed = n-1; // to point end

    long long int sum = 0; // to store sum
    while(st < ed){
        sum += abs(arr[st]-arr[ed]) + abs(arr[st+1]-arr[ed]);
        st++;
        ed--;
    }
    return sum+=abs(arr[0]-arr[st]); // because it is circular array
}
