#include <bits/stdc++.h>
using namespace std;


/*
给定一个字符串，逐个翻转字符串中的每个单词。
输入: "the sky is blue"
输出: "blue is sky the"
*/

/*
解决方法：首先将整个字符串反转，然后依次将每个单词反转。
要求O(1)的空间复杂度，即inplace反转。技巧是利用一个变量记录反转位置。
*/



string reverseWords(string s){
    int len = s.size();
    if(len < 1) return "";
    
    int idx = 0; // 用idx记录插入位置

    reverse(s.begin(), s.end());

    for(int st = 0; st < len; st++){
        if(s[st] == ' ') continue;
        // 插入空格
        if(idx != 0) s[idx++] = ' ';

        int ed = st;
        // 反转每个单词
        while(ed < len && s[ed] != ' ') s[idx++] = s[ed++];

        reverse(s.begin() + idx - (ed - st), s.begin() + idx);
        st = ed;
    }

    s.erase(s.begin() + idx, s.end());

    return s;
}





int main(){


    return 0;
}