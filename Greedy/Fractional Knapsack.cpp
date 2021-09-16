    // Problem Link : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
    
    /*  struct Item{
        int value;
        int weight;
    };*/
    // comparator function to sort Item array
    // It will sort an array in non decreasing order of value/weight
    static bool comp(Item a, Item b){
        return a.value/(float)a.weight > b.value/(float)b.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp); // sort array
        double ans = 0; // to store answer
        
        int i = 0; // to traverse array
        while(W > 0 && i < n){
            if(arr[i].weight <= W){ // if i can fully include this Item then i will
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{ // if i can not include it full then i will include its fractional part
                ans += (float)(arr[i].value)/arr[i].weight*W;
                W = 0;
            }
            i++;
        }
        return ans;
    }
