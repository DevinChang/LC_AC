#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int value = 0, count = 0;
        for(auto v : nums){
            if(count == 0){
                value = v;
                count++;
            }
            else{
                if(v != value) count--;
                else count++;
            }
        }
        return value;
    }
};