

string fractionToDecimal(int numerator, int denominator) {
    typedef long long LL; 
    LL x = numerator, y = denominator;
    if (x % y == 0) return to_string(x / y);
    string res;
    if((x < 0) ^ (y < 0)) res += "-";
    x = abs(x), y = abs(y);
    res += to_string(x / y) + ".";
    x %= y;
    unordered_map<LL, int> hash;
    while(x) {
        hash[x] = res.size();
        x *= 10;
        res += to_string(x / y);
        x %= y;
        if(hash.count(x)){
            res = res.substr(0, hash[x]) + "(" + res.substr(hash[x], res.size()) + ")";
            break;
        }
    }
    return res;
}