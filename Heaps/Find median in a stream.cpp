// Problem Link : https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#
class Solution
{
    public:
    priority_queue<int> max_heap; // it will store half smaller elements
    priority_queue<int,vector<int>,greater<int>> min_heap; // it will store another half larger elements
    
    // functiont to insert new value
    void insertHeap(int &x){
        if(max_heap.size() == min_heap.size()){ // if size of both heap are same then i will add a number into max_heap
            min_heap.push(x); // adding new element in min_heap
            int temp = min_heap.top(); // getting smallest element in min_heap
            min_heap.pop();
            max_heap.push(temp); // adding that element into max_heap
        }else{ // if size of max heap is larger then i will add a number in min heap
            max_heap.push(x); // adding new number in max_heap
            int temp = max_heap.top(); // getting largest number from max_heap
            max_heap.pop();
            min_heap.push(temp); // adding that element into min_heap
        }
    }
    //Function to return Median.
    double getMedian()
    {
        // if size of max_heap is larger then my heap contains odd number of elements so i will retuen extra element from max heap
        // and if size of both are same then heap has even elements so i willl return average of max element from max_heap and min element from min_heap
        if(max_heap.size() > min_heap.size())
            return max_heap.top();
        else
            return (max_heap.top()+min_heap.top())/2;
    }
};
