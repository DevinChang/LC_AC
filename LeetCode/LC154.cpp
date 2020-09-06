#include <iostream>
#include <vector>
using namespace std;





int findMind(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1; 
    while(l < r && nums[r] == nums[0]) r--;
    if(nums[r] > nums[l]) return nums[0];
    while(l < r){
        int mid = l + r >> 1;
        if (nums[mid] < nums[0]) r = mid;
        else l = mid + 1;
    }
    return nums[r];
}