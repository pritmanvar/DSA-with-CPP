// Problem Link : https://codeforces.com/problemset/problem/1556/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        // There are to cases.
        // case 1 : starting element of required array will be even
        // case 2 : starting element of required array will be odd
        int n;
        cin >> n;
        int odd = 0,even = 0; // to store number of even and odd elements.
        // to store index of even and odd elements when starting element of array will be even.
        set<int> see; // to store index of even->meaning : set to store index of even when starting element is even
        set<int> soe; // to store index of odd->meaning : set to store index of odd when starting element is even

        // to store index of even and odd elements when starting element of array will be odd.
        set<int> seo; // to store index of even->meaning : set to store index of even when starting element is odd
        set<int> soo; // to store index of odd->meaning : set to store index of odd when starting element is odd
        
        // taking input
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            if(temp%2 == 0){
                even++;
                see.insert(i);
                seo.insert(i);
            }else{
                odd++;
                soe.insert(i);
                soo.insert(i);
            }
        }
        // if difference between even and odd is larger than 1 then it is imposible to achive required array.
        if(abs(even-odd) > 1){
            cout << -1 << endl;
            continue;
        }
        
        // Case 1: 
        int count_even = 0;
        for(int i = 0; i < n; i++){
            // if current index is even and element at current index is odd then i have to do some work.
            if(i%2 == 0 && soe.count(i) == 1){
                int j = *see.upper_bound(i); // get nearest odd element in the right of it.
                // i need exactly j-i swaps to bring an element from jth index to ith index.
                count_even += j-i;

                // here i am swaping adjacent elements so this operation will be equivalent to rotate array of ith index to jth index by 1.
                // but in the array of ith index to jth index only even element is element at index j
                // so by rotaion ith element will become even and all other elements will be odd
                // so i will just swap these 2 element because i am just interested in even and odd.

                // after swaping ith index will contain even element so i will remove ith index from set of odd and add that into set of even and do same for jth index
                soe.erase(i);
                soe.insert(j);
                see.erase(j);
                see.insert(i);
            }
            // appllied same logic as above if statement but here i need odd element at ith index insted of even element.
            if(i%2 == 1 && see.count(i) == 1){
                int j = *soe.upper_bound(i);
                count_even += j-i;
                see.erase(i);
                see.insert(j);
                soe.erase(j);
                see.insert(i);
            }
        }
        // applied same logic as above loop but here starting element will be odd.
        int count_odd = 0;
        for(int i = 0; i < n; i++){
            if(i%2 == 0 && seo.count(i) == 1){
                int j = *soo.upper_bound(i);
                count_odd += j-i;
                seo.erase(i);
                seo.insert(j);
                soo.erase(j);
                soo.insert(i);
            }
            if(i%2 == 1 && soo.count(i) == 1){
                int j = *seo.upper_bound(i);
                count_odd += j-i;
                soo.erase(i);
                soo.insert(j);
                seo.erase(j);
                seo.insert(i);
            }
        }
        // starting element must be odd if odd is greater than even and even if even is greater than odd to get required array.
        // but if odd == even then starting element can be anything.
        if(odd > even){
            cout << count_odd << endl;
        }else if(odd < even){
            cout << count_even << endl;
        }else{
            cout << min(count_odd,count_even) << endl;
        }
    }
    return 0;
}
