//
// Created by devinchang on 2019/12/19.
//

#include "util.h"


bool isScramble(string s1, string s2){
    if(s1.size() != s2.size())
        return false;
    int len = s1.size();
    if(len == 1)
        return s1[0] == s2[0];
    vector<vector<vector<bool>>> dp(len+1, vector<vector<bool>>(len+1, vector<bool>(len+1, false)));
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            dp[1][i][j] = (s1[i] == s2[j]);
        }
    }
    for(int l = 2; l <= len; l++){
        for(int i = 0; i + l - 1 < len; i++){
            for(int j = 0; j + l - 1 < len; j++){
                for(int k = 1; k < l; k++){
                    if(dp[k][i][j] && dp[l-k][i+k][j+k]){
                        dp[l][i][j] = true;
                        break;
                    }
                    if(dp[k][i][j+l-k] && dp[l-k][i+k][j]){
                        dp[l][i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[len][0][0];
}


int main(){
    string line;
    while(getline(cin, line)){
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        bool ret = isScramble(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }

    return 0;
}

