class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        typedef unsigned long long ULL;
        const int P = 131;
        unordered_set<ULL> hash;
        for (auto& s: dictionary) {
            ULL h = 0;
            for (auto c: s) h = h * P + c;
            hash.insert(h);
        }

        stringstream ssin(sentence);
        string res, word;
        while (ssin >> word) {
            string s;
            ULL h = 0;
            for (auto c: word) {
                s += c;
                h = h * P + c;
                if (hash.count(h)) break;
            }
            res += s + ' ';
        }
        res.pop_back();
        return res;
    }
};