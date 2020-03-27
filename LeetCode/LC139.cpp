//
// Created by devinchang on 2019/12/26.
//

#include "util.h"


void wordBreak_recur(string s, int pos, vector<string>& wordDict, vector<int> &isbreak) {
    int len = s.size();
    if (pos == len) {
        isbreak[pos-1] = true;
        return;
    }
    if(isbreak[pos] != -1){
        return;
    }
    int dictlen = wordDict.size();
    for (int i = 0; i < dictlen; i++) {
        string str = wordDict[i];
        string substr = s.substr(pos, str.size());
        if (substr == wordDict[i]) {
            wordBreak_recur(s, pos + str.size(), wordDict, isbreak);
        }
    }
    if(isbreak[pos] == -1)
        isbreak[pos] = false;
    return;
}



bool wordBreak_recur(string s, vector<string>& wordDict){
    vector<int> isbreak(s.size(), -1);
    wordBreak_recur(s, 0, wordDict, isbreak);
    return isbreak[s.size()-1] == 1;
}

bool wordBreak(string s, vector<string>& wordDict){
    int len = s.size();
    vector<bool> dp(len+1, false);
    dp[0] = true;
    for(int i = 1; i <= len; i++){
        for(int j = 0; j < i; j++){
            if(dp[j]){
                string str = s.substr(j, i-j);
                if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[len];
}



int main(){
    string s = "leetcode";
    string s2 = "applepenapple";
    string s3 = "catsandog";
    string s4 = "a";
    vector<string> wordDict = {"leet", "code"};
    vector<string> wordDict2 = {"apple", "pen"};
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> wordDict4 = {"a"};

    bool ret = wordBreak(s, wordDict);
    bool ret2 = wordBreak(s2, wordDict2);
    bool ret3 = wordBreak(s3, wordDict3);
    bool ret4 = wordBreak(s4, wordDict4);

    string out = boolToString(ret);
    string out2 = boolToString(ret2);
    string out3 = boolToString(ret3);
    string out4 = boolToString(ret4);

    cout << out << endl;
    cout << out2 << endl;
    cout << out3 << endl;
    cout << out4 << endl;
    return 0;
}

