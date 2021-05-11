class Solution {
public:
    string toGoatLatin(string s) {
        unordered_set<char> S {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        string res;
        for(int i = 0, k = 1; i < n; i++) {
            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            string word = s.substr(i, j - i);
            i = j;
            if(S.count(tolower(word[0]))) word += "ma";
            else {
                word = word.substr(1) + word[0] + "ma";
            }
            word += string(k, 'a');
            k++;
            res += word + ' ';
        }
        res.pop_back();
        return res;
    }
};