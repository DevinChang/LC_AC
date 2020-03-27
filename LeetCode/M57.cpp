//
// Created by devinchang on 2020/2/26.
//
#include "util.h"
using namespace std;

const int N = 16;
int p[N] = {4, 0, 0, 0, 4, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0};


void addblock(int p[], int len){
    int newsize = ((len + 1) >> 1) << 1;
    int oldsize = *p & -2;
    *p = newsize | 1;
    if(newsize < oldsize)
        *(p + newsize) = oldsize - newsize;
}



vector<vector<int>> findContinousSequence(int target){
    if(target < 1)
        return {{0}};
    vector<vector<int>> res;
    vector<int> vec;
    int slow = 1, fast = slow+1;
    int middle = (1 + target) / 2;
    int sum = slow + fast;
    while(slow < middle){
        if(sum == target){
            for(int i = slow; i <= fast; i++)
                vec.push_back(i);
            res.push_back(vec);
            vec.clear();
        }
        while(slow < middle && sum > target){
            sum -= slow;
            slow++;
            if(sum == target){
                for(int i = slow; i <= fast; i++)
                    vec.push_back(i);
                res.push_back(vec);
                vec.clear();
            }
        }
        fast++;
        sum += fast;
    }
    return res;
}




int main(){
    string line;
    addblock(p+8, 4);
    while(getline(cin, line)){
        int target = stringToInteger(line);
        auto res = findContinousSequence(target);
        for(auto vv : res){
            cout << "[";
            for(auto v : vv)
                cout << v << ",";
            cout << "]";
        }
    }
    return 0;
}

