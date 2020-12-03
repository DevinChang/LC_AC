class Solution {
private:
    bool isFile(const string &name) {
        const int len = name.size();
        for (int i = len - 1; i >= 0; i--)
            if (name[i] == '.' && i != len - 1)
                return true;

        return false;
    }

    int getNextLevel(int &i, const string &input) {
        int res = 0;
        while (i < input.size() && (input[i] == '\t' || input[i] == '\n')) {
            if (input[i] == '\t')
                res++;
            i++;
        }
        return res;
    }

    string getNextName(int &i, const string &input) {
        string name;
        while (i < input.size() && input[i] != '\n') {
            name.push_back(input[i]);
            i++;
        }
        return name;
    }

public:
    int lengthLongestPath(string input) {
        stack<int> lengthStack, levelStack;
        int length = 0, maxLength = 0;
        int i = 0;
        while (i < input.size()) {
            int level = getNextLevel(i, input);
            string name = getNextName(i, input);
            while (!levelStack.empty() && levelStack.top() >= level) {
                length -= lengthStack.top();
                levelStack.pop();
                lengthStack.pop();
            }

            length += name.size();
            levelStack.push(level);
            lengthStack.push(name.size());

            if (isFile(name) && maxLength < length + level)
                maxLength = length + level;
        }

        return maxLength;
    }
};
