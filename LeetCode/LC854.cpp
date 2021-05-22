class Solution {
public:
    int h(string& s1, string& s2) {
        int res = 0;
        for (int i = 0; i < s1.size(); i ++ )
            if (s1[i] != s2[i])
                res ++ ;
        return (res + 1) / 2;
    }

    bool dfs(string& s1, string& s2, int depth) {
        if (!depth) return s1 == s2;
        if (h(s1, s2) > depth) return false;
        for (int i = 0; i < s1.size(); i ++ )
            if (s1[i] != s2[i]) {
                for (int j = i + 1; j < s1.size(); j ++ )
                    if (s2[i] == s1[j]) {
                        swap(s1[i], s1[j]);
                        if  (dfs(s1, s2, depth - 1)) return true;
                        swap(s1[i], s1[j]);
                    }
                break;
            }
        return false;
    }

    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        int depth = 1;
        while (!dfs(s1, s2, depth)) depth ++ ;
        return depth;
    }
};