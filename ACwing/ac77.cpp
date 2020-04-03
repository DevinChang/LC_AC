#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        if(len < 1) return "";
        
        int idx = 0;
        reverse(s.begin(), s.end());
        
        for(int i = 0; i < len; i++){
            if(s[i] == ' ') continue;

            int j = i;
            while(j < len && s[j] != ' ') s[idx++] = s[j++];

            reverse(s.begin() + idx + (j - i), s.begin() + idx);
        }
        return s;
    }

};