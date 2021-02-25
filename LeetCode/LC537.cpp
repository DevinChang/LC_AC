class Solution {
public:
    string complexNumberMultiply(string x, string y) {
        int a, b, c, d;
        sscanf(x.c_str(), "%d+%di", &a, &b);
        sscanf(y.c_str(), "%d+%di", &c, &d);
        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";
    }
};