#include <iostream>
#include <vector>
using namespace std;




int findMin(vector<int> &nums) {
    int l = 0, r = nums.size()- 1;
    if(nums[r] > nums[l]) return nums[0];
    while(l < r){
        int mid = l + r >> 1;
        if(nums[mid] > nums[0]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return nums[l];
}