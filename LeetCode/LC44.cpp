//
// Created by devinchang on 2019/12/17.
//

#include "util.h"


bool isMatch(string s, string p){
    if(p.size() < 1)
        return s.empty();
    int slen = s.size(), plen = p.size();
    vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= plen; i++){
        if(p[i-1] == '*')
            dp[0][i] = dp[0][i-1];
    }
    for(int i = 1; i <= slen; i++){
        for(int j = 1; j <= plen; j++){
            if(p[j-1] != '*'){
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[slen][plen];
}



int main(){
    string line;
    while(getline(cin, line)){
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = isMatch(s, p);
        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

