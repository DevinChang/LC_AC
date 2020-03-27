//
// Created by devinchang on 2019/12/27.
//

#include "util.h"

void wordBreak_WA(string s, int pos, vector<string>& wordDict, vector<int> &dp,
        vector<string> &res, string &str){
    if(pos == s.size()){
        dp[pos-1] = 1;
        res.push_back(str);
        return;
    }
    if(dp[pos] != -1){
        return;
    }
    int len = wordDict.size();
    for(int i = 0; i < len; i++){
        if(s.substr(pos, wordDict[i].size()) == wordDict[i]){
            string tmp = str;
            if(pos + wordDict[i].size() == s.size())
                str += wordDict[i];
            else
                str += wordDict[i] + " ";
            //dp[pos] = 1;
            wordBreak_WA(s, pos+wordDict[i].size(), wordDict, dp, res, str);
            str = tmp;
        }
    }
    if(dp[pos] != -1)
        dp[pos] = 0;
    return;
}

vector<string> wordBreak(string s, vector<string>& wordDict,
        unordered_map<string, vector<string>> &imap){
    if(imap.count(s))
        return imap[s];
    if(s.empty())
        return {""};
    vector<string> res;
    for(int i = 0; i < wordDict.size(); i++){
        if(s.substr(0, wordDict[i].size()) == wordDict[i]){
            vector<string> tmp = wordBreak(s.substr(wordDict[i].size()), wordDict, imap);
            for(auto t : tmp){
                res.push_back(wordDict[i] + (t.empty() ? "" : " ") + t);
            }
        }
    }
    imap[s] = res;
    return res;
}

vector<string> wordBreak(string s, vector<string>& wordDict){
    unordered_map<string, vector<string>> imap;
    return wordBreak(s, wordDict, imap);
}

vector<string> wordBreak_DP(string s, vector<string>& wordDict){
    int len = s.size();
    vector<vector<string>> dp(len+1);
    dp[0] = {""};
    unordered_set<string> imap(wordDict.begin(), wordDict.end());
    for(int i = 1; i <= len; i++){
        vector<string> tmp;
        for(int j = 0; j < i; j++){
            if(dp[j].size() > 0 && imap.count(s.substr(j, i-j))){
                for(auto str : dp[j]){
                    tmp.push_back(str+(str.empty() ? "" : " ") + s.substr(j, i-j));
                }
            }
        }
        dp[i] = tmp;
    }
    return dp[len];
}


int main(){
    string s1 = "catsanddog";
    vector<string> dict1 = {"cat", "cats", "and", "sand", "dog"};
    //auto ret1 = wordBreak(s1, dict1);
    auto ret1 = wordBreak_DP(s1, dict1);
    for(auto r1 : ret1){
        cout << r1 << endl;
    }

    string s2 = "pineapplepenapple";
    vector<string> dict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    //auto ret2 = wordBreak(s2, dict2);
    auto ret2 = wordBreak_DP(s2, dict2);
    for(auto r2 : ret2){
        cout << r2 << endl;
    }


    string s3 = "catsandog";
    vector<string> dict3 = {"cat", "cats", "and", "sand", "dog"};
    //auto ret3 = wordBreak(s3, dict3);
    auto ret3 = wordBreak_DP(s3, dict3);
    for(auto r3 : ret3){
        cout << r3 << endl;
    }
    return 0;
}

