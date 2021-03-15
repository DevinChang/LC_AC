class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    string fractionAddition(string expression) {
        int n = 0;
        // 统计分数的个数
        for(auto c : expression) {
            if(c == '/') n++;
        }
        // format
        expression = '+' + expression;
        // a / b + c / d = (ad + bc) / bd
        int a = 0, b = 1, c = 0, d = 1;
        int offset = 0;
        char e;
        for(int i = 0; i < n; i++) {
            sscanf(expression.c_str() + offset, "%c%d/%d", &e, &c, &d);
            offset += (e + to_string(c) + '/' + to_string(d)).size();
            if (e == '-') c = -c;
            int x = a * d + b * c;
            int y = b * d;
            // gcd
            int z = gcd(x, y);
            a = x / z;
            b = y / z; 
        }
        if(b < 0) a = -a, b = -b;
        return to_string(a) + '/' + to_string(b);
    }
};