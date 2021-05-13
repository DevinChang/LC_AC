class Solution {
public:
    string work_email(string& t) {
        string s;
        for (auto c: t) s += tolower(c);
        int a = s.find('@'), b = s.find('.');
        string name1 = s.substr(0, a);
        string name2 = s.substr(a + 1, b - a - 1);
        string name3 = s.substr(b + 1);
        return name1[0] + string(5, '*') + name1.back() + '@' + name2 + '.' + name3;
    }

    string work_phone(string t) {
        string s;
        for (auto c: t)
            if (isdigit(c))
                s += c;
        if (s.size() == 10)
            return "***-***-" + s.substr(6);
        return "+" + string(s.size() - 10, '*') + "-***-***-" + s.substr(s.size() - 4);
    }

    string maskPII(string s) {
        if (s.find('@') != -1)
            return work_email(s);
        else
            return work_phone(s);
    }
};