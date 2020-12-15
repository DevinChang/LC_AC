class Solution {
public:
    vector<int> add(vector<int> A, vector<int> B) {
        vector<int> C;
        for(int i = 0, t = 0; i < A.size() || i < B.size() || t; i++) {
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            C.push_back(t % 10);
            t /= 10;
        }
        return C;
    }

    string addStrings(string a, string b) {
        vector<int> A, B;
        for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');
        for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i]-'0');
        auto C = add(A, B);
        string ret;
        for(int i = C.size()-1; i >= 0; i--) ret += to_string(C[i]);
        return ret;
    }
};