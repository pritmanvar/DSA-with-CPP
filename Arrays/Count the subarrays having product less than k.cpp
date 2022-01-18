// problem Link : https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    vector<ull> ugly;
	    unordered_set<ull> st;
	    ugly.push_back(1);
	    st.insert(1);
	    int i2 = 0, i3 = 0, i5 = 0; 
	    
	    while(ugly.size() < n){
	        if(ugly[i2]*2 <= ugly[i3]*3 && ugly[i2]*2 <= ugly[i5]*5){
	            if(st.count(ugly[i2]*2) == 0){
	                ugly.push_back(ugly[i2]*2);
	            }
	            st.insert(ugly.back());
	            i2++;
	        }else if(ugly[i3]*3 <= ugly[i2]*2 && ugly[i3]*3 <= ugly[i5]*5){
	            if(st.count(ugly[i3]*3) == 0){
	                ugly.push_back(ugly[i3]*3);
	                
	            }
	            st.insert(ugly.back());
	            i3++;
	        }else{
	            if(st.count(ugly[i5]*5) == 0){
	                ugly.push_back(ugly[i5]*5);
	            }
	            st.insert(ugly.back());
	            i5++;
	        }
	    }
	    return ugly[n-1];
	}
};
