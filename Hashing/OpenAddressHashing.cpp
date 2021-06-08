// This hash table works for only non negative integers.
#include<bits/stdc++.h>

using namespace std;

class OpenAddressHashing
{
    // deleted = -2
    // empty = -1
private:
    int capacity;
    int sz = 0;
    vector<int> myhash;
    int hash(int key){
        return key%capacity;
    }
public:
    OpenAddressHashing(int cap){
        capacity = cap;
        myhash.resize(capacity);
        for(int i = 0; i < capacity; i++){
            myhash[i] = -1;
        }
    }
    bool search(int key){
        int h = hash(key);
        int i = h;
        while(myhash[i] != -1){
            if(myhash[i] == key){
                return true;
            }
            i = (i+1)%capacity;
            if(i == h){
                return false;
            }
        }
        return false;
    }
    bool insert(int key){
        if(sz == capacity || search(key)){
            return false;
        }
        int h = hash(key);
        int i = h;
        while(myhash[i] != -1 && myhash[i] != -2){
            i = (i+1)%capacity;
        }
        myhash[i] = key;
        sz++;
        return true;
    }
    bool remove(int key){
        int h = hash(key);
        int i = h;
        while(myhash[i] != -1){
            if(myhash[i] == key){
                myhash[i] = -2;
                sz--;
                return true;
            }
            i = (i+1)%capacity;
            if(i == h){
                if(myhash[i] == key){
                    myhash[i] = -2;
                    sz--;
                    return true;
                }
                return false;
            }
        }
        return false;
    }
    int size(void){
        return sz;
    }
};

int main() 
{
    int capacity;
    cout << "Enter the capacity of hash table" << endl;
    cin >> capacity;

    // NOTE : Commented output is for the hash table of capacity 10. For different capacity this output may change.

    OpenAddressHashing hash(capacity);
    cout << "Result of insert 1 is " << hash.insert(1) << endl; // returns true because it will add 1 successfully in hash table
    cout << "Result of insert 2 is " << hash.insert(2) << endl; // returns true because it will add 2 successfully in hash table
    cout << "Result of insert 3 is " << hash.insert(3) << endl; // returns true because it will add 3 successfully in hash table
    cout << "Result of insert 4 is " << hash.insert(4) << endl; // returns true because it will add 4 successfully in hash table
    cout << "Result of insert 5 is " << hash.insert(5) << endl; // returns true because it will add 5 successfully in hash table
    cout << "Result of insert 6 is " << hash.insert(6) << endl; // returns true because it will add 6 successfully in hash table
    cout << "Result of insert 7 is " << hash.insert(7) << endl; // returns true because it will add 7 successfully in hash table
    cout << "Result of insert 8 is " << hash.insert(8) << endl; // returns true because it will add 8 successfully in hash table
    cout << "Result of insert 9 is " << hash.insert(9) << endl; // returns true because it will add 9 successfully in hash table
    cout << "Result of insert 10 is " << hash.insert(10) << endl; // returns true because it will add 10 successfully in hash table
    cout << "Result of insert 1 is " << hash.insert(1) << endl << endl; // returns false because it can not add 1 in the hash table as it is already present in the hash table

    cout << "Result of search 1 is " << hash.search(1) << endl; // returns true because 1 is present in the hash table
    cout << "Result of search 11 is " << (bool)hash.search(11) << endl << endl; // returns false because 11 is not present in the hash table
    
    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table

    cout << "Result of remove 10 is " << hash.remove(10) << endl << endl; // returns true because it will successfully remove 10 from hash table

    cout << "Result of search 10 is " << hash.search(10) << endl << endl; // returns false because 10 is not present in the hash table

    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table

    cout << "Result of insert 10 is " << hash.insert(10) << endl << endl; // returns true because it will add 10 successfully in hash table
    
    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table
    
    cout << "Result of remove 12 is " << hash.remove(12) << endl << endl; // returns false because it can not remove 12 from hash table as it is not present in the hash table

    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table
    
    cout << "Result of insert 15 is " << hash.insert(15) << endl << endl; // returns false because hash table is full
    
    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table
    return 0;
}
