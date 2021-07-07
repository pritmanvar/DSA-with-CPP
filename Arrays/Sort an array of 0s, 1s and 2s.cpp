// Problem Link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

void sort012(int arr[], int n)
    {
        // coode here 
        
        int i = 0;// This is to Points the first non 0 from current posion
        int j = 0;// This pointer is used to trsaverse the array
        int k = n-1;// This is to point the last non 2 element in array
        
        // traverse through all array
        while(j <= k){
            if(arr[j] == 0){ // If element is 0 then swap it with first non zero element
                swap(arr[i],arr[j]);
                i++;
                j++;
            }else if(arr[j] == 2){ //If element is 2 then swap it with last non 2 element in array
                swap(arr[j],arr[k]);
                k--;
                j++;
            }else{ // simply skip one because we are putting 0 at begin and 2 at last so automaticly 1 will be at middle
                j++;
            }
        }
    }
