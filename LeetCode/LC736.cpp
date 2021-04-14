typedef unordered_map<string, int> MPSI;

class Solution {
public:
    int evaluate(string expression) {
        int k = 0;
        return dfs(expression, k, MPSI());
    }

    int get_value(string& str, int& k, MPSI vars) {
        int value;
        if (str[k] == '-' || isdigit(str[k])) {
            int i = k + 1;
            while (isdigit(str[i])) i ++ ;
            value = stoi(str.substr(k, i - k));
            k = i;
        } else if (str[k] != '(') {
            string name;
            while (str[k] != ' ' && str[k] != ')') name += str[k ++ ];
            value = vars[name];
        } else {
            value = dfs(str, k, vars);
        }
        return value;
    }

    int dfs(string& str, int& k, MPSI vars) {
        int value;
        k ++ ;  // 跳过 '('
        auto type = str.substr(k, 3);
        if (type == "let") {
            k += 4;  // 跳过 "let "
            while (str[k] != ')') {
                if (str[k] == '(' || str[k] == '-' || isdigit(str[k])) {
                    value = get_value(str, k, vars);
                    break;
                }
                string name;
                while (str[k] != ' ' && str[k] != ')') name += str[k ++ ];
                if (str[k] == ')') {
                    value = vars[name];
                    break;
                }
                k ++ ;  // 跳过 ' '
                vars[name] = get_value(str, k, vars);
                k ++ ;  // 跳过 ' '
            }
        } else if (type == "add") {
            k += 4;  // 跳过 "add "
            int a = get_value(str, k, vars);
            k ++ ;  // 跳过 ' '
            int b = get_value(str, k, vars);
            value = a + b;
        } else {
            k += 5;  // 跳过 "mult "
            int a = get_value(str, k, vars);
            k ++ ;  // 跳过 ' '
            int b = get_value(str, k, vars);
            value = a * b;
        }
        k ++ ;  // 跳过 ')'
        return value;
    }
};