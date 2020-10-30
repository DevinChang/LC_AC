

bool wordPattern(string pattern, string s) {
    // 分割空格字符
    stringstream raw(s);
    vector<string> str;
    string line;
    while(raw >> line) str.push_back(line);
    int n = pattern.size();
    if(str.size() != n) return false;
    unordered_map<char, string> ps;
    unordered_map<string, char> sp;
    for(int i = 0; i < n; i++){
        if(ps.count(pattern[i]) == 0)  ps[pattern[i]] = str[i];
        if(sp.count(str[i]) == 0) sp[str[i]] = pattern[i];
        if(ps[pattern[i]] != str[i]) return false;
        if(sp[str[i]] != pattern[i]) return false;
    }
    return true;
}