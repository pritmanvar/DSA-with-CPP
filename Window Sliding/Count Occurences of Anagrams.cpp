// Problem Link : https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window
	int search(string pat, string txt) {
	    int countwin[256] = {0};
	    int countprt[256] = {0};
	    int count = 0;
	    // counting frequancy of 1st window
	    for(int i = 0; i < pat.length(); i++){
	        countwin[txt[i]]++;
	        countprt[pat[i]]++;
	    }
	    // go though all window and check that both count arrays are same or not
	    // it same then it is an anagram
	    for(int i = pat.length(); i <= txt.length(); i++){
	        if(cmp(countwin,countprt))
	            count++;
	        countwin[txt[i]]++;
	        countwin[txt[i-pat.length()]]--;
	    }
	    return count;
	}
	//function for comparimg arrays
    bool cmp(int arr1[],int arr2[]){
        for(int i = 0; i < 256; i++){
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }