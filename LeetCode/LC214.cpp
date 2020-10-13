
string shortestPalindrome(string s){
    int n = s.size();
    string t(s.rbegin(), s.rend());
    string str(s + "#" + t);

    vector<int> nxt(2 * n + 1);

    int j = -1;
    nxt[0] = -1;

    for (int i = 1; i < 2 * n + 1; i++) {
        while (j > -1 && str[j + 1] != str[i]) j = nxt[j];
        if (str[j + 1] == str[i])
            j++;

        nxt[i] = j;
    }

    return t.substr(0, n - nxt[2 * n] - 1) + s;
}