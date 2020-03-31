#include <bits/stdc++.h>
using namespace std;



int search(vector<int> &nums, int target){
    int len = nums.size();
    if(len < 1) return -1;
    int left = 0, right = len - 1;
    while(left < right){
        int mid = (left+right) >> 1;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < nums[right]){
            if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        else{
            if(nums[mid] < target) left = mid+1;
            else right = mid - 1;
        }
    }
    return -1;
}

// 先找旋转数组中旋转点的做法
int search2(vector<int> &nums, int target){
    int lo=0,hi=n-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(A[mid]>A[hi]) lo=mid+1;
        else hi=mid;
    }
    int rot=lo;
    lo=0;hi=n-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int realmid=(mid+rot)%n;
        if(A[realmid]==target)return realmid;
        if(A[realmid]<target)lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}



int main(){


    return 0;
}