//
// Created by devinchang on 2020/1/2.
//
#include "util.h"


int maxProfit(vector<int>& prices){
    int len = prices.size();
    if(len <= 1)
        return 0;
    vector<int> s1(len, 0);
    vector<int> s2(len, 0);
    vector<int> s3(len, 0);
    s1[0] = -prices[0];
    s2[0] = INT_MIN;
    s3[0] = 0;
    for(int i = 1; i < len; i++){
        s1[i] = max(s1[i-1], s3[i-1]-prices[i]);
        s2[i] = s1[i-1] + prices[i];
        s3[i] = max(s3[i-1], s2[i-1]);
    }
    return max(s1[len-1], max(s2[len-1], s3[len-1]));
}


int main(){
    string line;
    while(getline(cin, line)){
        vector<int> prices = stringToIntegerVector(line);
        int ret = maxProfit(prices);
        cout << to_string(ret) << endl;
    }

    return 0;
}

