string removeDuplicateLetters(string s) {
    unordered_map<char, bool> ins;
    unordered_map<char, int> last;
    string res;
    int n = s.size();
    for(int i = 0; i < n; i++) last[s[i]] = i;
    for(int i = 0; i < n; i++){
        if(ins[s[i]]) continue;
        while(res.size() && res.back() > s[i] && last[res.back()] > i){
            res.pop_back();
            ins[s[i]] = false;
        }
        res += s[i];
        ins[s[i]] = true;
    }
    return res;
}