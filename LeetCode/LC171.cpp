
int titleToNumber(string s) {
    int n = s.size();
    int a = 0;
    for(long long i = 0, p = 26; i < n-1; i++, p *= 26) a += p;
    int b = 0;
    for(auto c : s) b = b * 26 + c - 'A';
    return a + b + 1;
}