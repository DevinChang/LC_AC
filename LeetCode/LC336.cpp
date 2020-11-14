class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> S;
        for (int i = 0; i < words.size(); i ++ )
        {
            string key = words[i];
            reverse(key.begin(), key.end());
            S[key] = i;
        }
        vector<vector<int>> res;
        if (S.count(""))
        {
            for (int i = 0; i < words.size(); i ++ )
                if (words[i] != "" && is_palindrome(words[i]))
                    res.push_back({S[""], i});
        }
        for (int i = 0; i < words.size(); i ++ )
            for (int j = 0; j < words[i].size(); j ++ )
            {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (S.count(left) && is_palindrome(right) && S[left] != i) res.push_back({i, S[left]});
                if (S.count(right) && is_palindrome(left) && S[right] != i) res.push_back({S[right], i});
            }
        return res;
    }

    bool is_palindrome(string &word)
    {
        for (int i = 0, j = word.size() - 1; i < j; i ++ , j -- )
            if (word[i] != word[j])
                return false;
        return true;
    }

};