class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0;
        for(auto c : t){
            if(k < s.size() && c == s[k]) k++;
        }
        return k == s.size();
    }

};