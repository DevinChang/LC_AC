class Solution {
public:
    const int p = 1337;

    int qmi(int a, int b) {
        a %= p;
        int res = 1;
        while(b) {
            if(b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int k = b.back();
        b.pop_back();
        return qmi(superPow(a, b), 10) * qmi(a, k) % p;
    }
};