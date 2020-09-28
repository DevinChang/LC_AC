

bool isIsomorphic(string s, string t) {
    int sn = s.size(), tn = t.size();
    if(sn != tn) return false;
    unordered_map<char, char> st, ts;
    for(int i = 0; i < sn; i++) {
        int a = s[i], b = t[i];
        if(st.count(a) && st[a] != b) return false;
        st[a] = b;
        if(ts.count(b) && ts[b] != a) return false;
        ts[b] = a;
    }
    return true;
}