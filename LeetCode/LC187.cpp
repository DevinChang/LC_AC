


vector<string> findRepeatedSequence(string s){
    vector<string> ret;
    unordered_map<string, int> hash;
    int n = s.size();
    for(int i = 0; i < n; i++){
        string tmp = s.substr(i, 10);
        if(hash[tmp] == 1) ret.push_back(tmp);
        hash[tmp]++;
    }
    return ret;
}