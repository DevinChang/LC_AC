//
// Created by devinchang on 2019/12/16.
//

#include "util.h"


bool isMatch(string s, string p){
    if(p.empty())
        return s.empty();
    int slen = s.size(), plen = p.size();
    vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= slen; i++)
        dp[i][0] = false;
    for(int j = 1; j <= plen; j++)
        dp[0][j] = j > 1 && p[j-1] == '*' && dp[0][j-2];
    for(int i = 1; i <= slen; i++){
        for(int j = 1; j <= plen; j++){
            if(p[j-1] != '*'){
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
            else{
                dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
            }
        }
    }
    return dp[slen][plen];
}


bool isMatch_recur(string s, string p){
    if(p.empty()) return s.empty();
    bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
    if(p.size() >= 2 && p[1] == '*'){
        return (firstMatch && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
    } else
        return firstMatch && isMatch(s.substr(1), p.substr(1));
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

