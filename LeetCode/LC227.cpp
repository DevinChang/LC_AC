
stack<int> num;
stack<char> op;

void eval() {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    int r;
    if (c == '+') r = a + b;
    else if (c == '-') r = a - b;
    else if (c == '*') r = a * b;
    else r = a / b;
    num.push(r);
}

int calculate(string s) {
    unordered_map<char, int> pr;
    pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
    for (int i = 0; i < s.size(); i ++ ) {
        char c = s[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j ++ ] - '0');
            num.push(x);
            i = j - 1;
        } else {
            while (op.size() && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }
    while (op.size()) eval();
    return num.top();
}
