#include <iostream>
#include <algorithm>
using namespace std;

/*
寻找峰值
*/



// Forward declaration of queryAPI.
// int query(int x);
// return int means nums[x].

class Solution {
public:
    int findPeakElement(int n) {
        int l = 0, r = n-1;
        while(l < r) {
            int mid = l + r >> 1;
            if(query(mid) < query(mid+1)) l = mid+1;
            else r = mid;
        }
        return r;
    }
};