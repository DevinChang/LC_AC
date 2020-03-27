//
// Created by devinchang on 2019/12/9.
//

#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, int first, vector<vector<int>> &ret, vector<int> &subset){
    ret.push_back(subset);

    for(int i = first; i < nums.size(); i++){
        if(i == first || nums[i] != nums[i-1]) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, ret, subset);
            subset.pop_back();
        }
    }
}

vector<vector<int>> subsetWithDup(vector<int> &nums){
    vector<int> subset;
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    backtrack(nums, 0, ret, subset);
    for(auto v : ret){
        for(auto n : v)
            cout << n << " ";
        cout << endl;
    }
}


int main(){
    vector<int> nums{4, 4, 4, 1, 4};
    subsetWithDup(nums);
    return 0;
}

