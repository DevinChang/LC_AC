
void eval(stack<int> &nums, stack<char> &op) {
    auto y = nums.top();
    nums.pop();
    auto x = nums.top();
    nums.pop();
    auto c = op.top();
    op.pop();
    if(c == '+') nums.push(x + y);
    else nums.push(x - y);
}


int calculate(string s) {
    stack<char> op;
    stack<int> nums;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(c == ' ') continue;
        if(isdigit(c)){
            int x = 0, j = i;
            while(isdigit(s[j]) && j < n) x = x * 10 + (s[j++] - '0');
            i = j - 1;
            nums.push(x);
        } else if (c == ')') {
            int j = i;
            while(op.top() != '(') eval(nums, op);
            op.pop();
        }
        else if (c == '(') op.push(c);
        else {
            while(op.size() && op.top() != '(') eval(nums, op);
            op.push(c);
        }
    }
    while(op.size()) eval(nums, op);
    return nums.top();
}