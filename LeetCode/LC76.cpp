#include <bits/stdc++.h>
using namespace std;

/*
最小覆盖子串

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"


思路：利用滑动窗口的特性，并用一个变量记录窗口是否滑动
*/

string minWindow(string s, string t){
    int slen = s.size(), tlen = t.size();
    int ihash[128] = {0};
    for(auto c : t) ihash[c]++;
    int left = 0, right = 0, start = 0, count = 0;
    int min = INT_MAX;
    while(right < slen){
        // 判断是否满足要求
        if(ihash[s[right++]]-- > 0) count++;
        // 满足要求，即t中所有字符都在s中出现,移动窗口
        while(count == tlen){
            if(right - left < min){
                mid = right - left;
                start = left;
            }
            // 移动窗口
            if(++ihash[s[left++]] > 0) count--;
        }
    }
    return min == INT_MAX ? "" : s.substr(start, min);
}



int main(){


    return 0;
}