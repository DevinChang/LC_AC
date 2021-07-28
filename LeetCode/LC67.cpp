class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n = a.size(), m = b.size();
        int t = 0;
        for(int i = n-1, j = m -1; i >= 0 || j >= 0;) {
            if(i >= 0) t += a[i--] - '0'; 
            if(j >= 0) t += b[j--] - '0';
            res += to_string(t % 2);
            t /= 2;
        }
        if(t) res += to_string(t);
        reverse(res.begin(), res.end());
        return res;
    }
};