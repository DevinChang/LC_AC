


string convertToTile(int n) {
    int k = 1;
    for(long long p = 26; n > p; p *= 26){
        n -= p;
        k++;
    }
    string res;
    n--;
    while(k--) {
        res += n%26 + 'A';
        n /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}