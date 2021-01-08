class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        unordered_map<char, int> cnt;
        for(int i = 0, j = 0; i < n;) {
            j = i + 1;
            // 分段
            while(j < n && (p[j] - p[j-1]==1 || p[j] - p[j-1] == -25)) j++;
            // 统计分段内以每个字母开头的子串的最大长度
            while(i < j) { 
                cnt[p[i]] = max(cnt[p[i]], j - i);
                i++;
            }
        }
        int res = 0;
        for(auto [a, b] : cnt) res += b;
        return res;
    }
};