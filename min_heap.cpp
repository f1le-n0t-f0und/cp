# include <bits/stdc++.h>
using namespace std;

// Edited from max_heap on 10/25/25.
struct min_heap{
    vector<int> val;
    int len = 0;
    
    void ins(int key){
        // Inserts a key.
        ++len;
        val.push_back(key);
        uhp(key);
    }
    void del(int key){
        // Deletes a key. -1 is top.
        if(len == 0){
            return;
        }
        if(key == -1){
            key = val[0];
        }
        int loc = -1;
        for(int x = 0; x < len; x++){
            if(val[x] == key){
                loc = x;
                break;
            }
        }
        if(loc == -1){
            return;
        }
        swp(loc, len - 1);
        val.resize(len - 1);
        --len;
        dhp(val[loc]);
    }
    void swp(int id1, int id2){
        // Swaps two keys.
        int tmp = val[id1];
        val[id1] = val[id2];
        val[id2] = tmp;
    }
    void uhp(int key){
        // Up-heaps a (non-sorted) key.
        int loc = -1;
        for(int x = 0; x < len; x++){
            if(val[x] == key){
                loc = x;
                break;
            }
        }
        if(loc == -1){
            return;
        }
        else{
            while(true){
                if(val[loc] < val[(loc - 1) / 2]){
                    swp(loc, (loc - 1) / 2);
                    loc = (loc - 1) / 2;
                }
                else{
                    break;
                }
            }
        }
    }
    void dhp(int key){
        // Down-heaps a (non-sorted) key.
        if(len < 2){
            return;
        }
        int loc = -1;
        for(int x = 0; x < len; x++){
            if(val[x] == key){
                loc = x;
                break;
            }
        }
        if(loc == -1){
            return;
        }
        else{
            while(true){
                bool l1 = false, l2 = false;
                if(len > 2 * loc + 1 && val[loc] > val[2 * loc + 1]){
                    l1 = true;
                }
                if(len > 2 * loc + 2 && val[loc] > val[2 * loc + 2]){
                    l2 = true;
                }
                if(!(l1 || l2)){
                    break;
                }
                else if(l1 && l2){
                    if(val[2 * loc + 1] > val[2 * loc + 2]){
                        swp(loc, 2 * loc + 2);
                        loc = 2 * loc + 2;
                    }
                    else{
                        swp(loc, 2 * loc + 1);
                        loc = 2 * loc + 1;
                    }
                }
                else{
                    if(l1){
                        swp(loc, 2 * loc + 1);
                        loc = 2 * loc + 1;
                    }
                    else{
                        swp(loc, 2 * loc + 2);
                        loc = 2 * loc + 2;
                    }
                }
            }
        }
    }
    int min(){
        // Returns the minimum element without deleting it.
        return val[0];
    }

    void __debug(){
        // For debug purposes.
        for(int x = 0; x < len; x++){
            cout << val[x] << ' ';
        }
        cout << endl;
    }
};
