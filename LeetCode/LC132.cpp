//
// Created by devinchang on 2019/12/26.
//

#include "util.h"


int minCut(string s){
    int len = s.size();
    if(s.size() < 1)
        return 0;
    vector<vector<bool>> pal(len, vector<bool>(len, false));
    vector<int> dp(len, 0);
    for(int i = len - 1; i >= 0; i--){
        // initialize dp[i]
        dp[i] = len - i - 1;
        for(int j = i; j < len; j++){
            if(s[i] == s[j] && (j - i < 2 || pal[i+1][j-1])){
                pal[i][j] = true;
                if(j == len-1)
                    dp[i] = 0;
                else{
                    dp[i] = min(dp[i], dp[j+1] + 1);
                }
            }
        }
    }
    return dp[0];
}




int main(){
    string line;
    while(getline(cin, line)){
        string s = stringToString(line);
        int ret = minCut(s);
        cout << ret << endl;
    }

    return 0;
}

