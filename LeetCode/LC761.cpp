class Solution {
public:
    string makeLargestSpecial(string S) {
        if(S.size() < 2) return S;
        vector<string> q;
        string s;
        int cnt = 0;
        for(auto c : S) {
            s += c;
            if(c == '1') cnt++;
            else {
                cnt--;
                if(cnt == 0) {
                    q.push_back('1' + makeLargestSpecial(s.substr(1, s.size()-2)) + '0');
                    s.clear();
                }
            }
        }
        sort(q.begin(), q.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        string res;
        for(auto s : q) res += s;
        return res;
    }
};