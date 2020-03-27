//
// Created by devinchang on 2019/12/24.
//

#include "util.h"


int maxProfit(vector<int> &prices){
    int len = prices.size();
    if(len < 1)
        return 0;
    int buy = prices[0];
    int maxprofit = 0;
    for(int i = 1; i < len; i++){
        if(prices[i] <= buy)
            buy = prices[i];
        else{
            maxprofit = max(maxprofit, prices[i] - buy);
        }
    }
    return maxprofit;
}



int main(){
    string line;
    while(getline(cin, line)){
        vector<int> prices = stringToIntegerVector(line);
        int ret = maxProfit(prices);
        cout << ret << endl;
    }
    return 0;
}

