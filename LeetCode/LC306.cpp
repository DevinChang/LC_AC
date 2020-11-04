class Solution {
public:

    string add(string x, string y){
        vector<int> A, B, C;
        int xn = x.size(), yn = y.size();
        for(int i = xn-1; i >= 0; i--) A.push_back(x[i] - '0');
        for(int i = yn-1; i >= 0; i--) B.push_back(y[i] - '0');
        int An = A.size(), Bn = B.size();
        for(int i = 0, t = 0; i < An || i < Bn || t; i++){
            if(i < An) t += A[i];
            if(i < Bn) t += B[i];
            C.push_back(t % 10);
            t /= 10;
        }
        string z;
        for(int i = C.size() - 1; i >= 0; i--) z += to_string(C[i]);
        return z;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j+1 < n; j++){
                int a = -1, b = i, c = j;
                while(true){
                    if(b -a > 1 && num[a+1] == '0' || c - b > 1 && num[b+1] == '0') break;
                    auto x = num.substr(a+1, b-a), y = num.substr(b+1, c-b);
                    auto z = add(x, y);
                    if(num.substr(c+1, z.size()) != z) break;
                    a = b, b = c, c += z.size();
                    if(c + 1 == num.size()) return true;
                }
            }
        }
        return false;
    }
};