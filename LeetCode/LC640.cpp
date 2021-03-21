class Solution {
public:
    pair<int,int> work(string str) {
        int a = 0, b = 0;
        if (str[0] != '+' && str[0] != '-') str = '+' + str;
        for(int i = 0; i < str.size(); i++) {
            int j = i + 1;
            while(j < str.size() && isdigit(str[j])) j++;
            int c = 1;
            // 不存在常数项
            if (i + 1 <= j - 1) c = stoi(str.substr(i + 1, j - 1 - i));
            if(str[i] == '-') c = -c;
            // 判断是常数项还是一次项
            if(j < str.size()  && str[j] == 'x') {
                a += c;
                // 若是一次项，则需要跳过x的位置
                i = j;
            } else {
                b += c;
                i = j - 1;
            }
        }
        return {a, b};
    }
    
    string solveEquation(string equation) {
        int k = equation.find('=');
        auto left = work(equation.substr(0, k));
        auto right = work(equation.substr(k+1));
        int a = left.first - right.first;
        int b = right.second - left.second;
        if(!a) {
            if (!b) return "Infinite solutions";
            else return "No solution";
        }
        return "x=" + to_string(b / a);
    }
};