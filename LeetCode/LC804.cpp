class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string pos[26] = {
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",
            ".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> S;
        for (auto& w: words) {
            string s;
            for (auto c: w) s += pos[c - 'a'];
            S.insert(s);
        }
        return S.size();
    }
};