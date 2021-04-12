class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string str;
        for (auto& s: source) str += s + '\n';
        vector<string> res;
        string line;

        for (int i = 0; i < str.size(); ) {
            if (i + 1 < str.size() && str[i] == '/' && str[i + 1] == '/') {
                while (str[i] != '\n') i ++ ;
            } else if (i + 1 < str.size() && str[i] == '/' && str[i + 1] == '*') {
                i += 2;
                while (str[i] != '*' || str[i + 1] != '/') i ++ ;
                i += 2;
            } else if (str[i] == '\n') {
                if (line.size()) {
                    res.push_back(line);
                    line.clear();
                }
                i ++ ;
            } else {
                line += str[i];
                i ++ ;
            }
        }
        return res;
    }
};