class Solution {
public:
    struct Node {
        Node *nxt[26];
        bool end_of_root;
        Node() {
            memset(nxt, NULL, sizeof(nxt));
            end_of_root = false;
        }
    };
    Node *rt = new Node();

    void insert(const string &s) {
        int l = s.length();
        Node *p = rt;
        for (int i = 0; i < l; i++) {
            if (p -> nxt[s[i] - 'a'] == NULL)
                p -> nxt[s[i] - 'a'] = new Node();
            p = p -> nxt[s[i] - 'a'];
            if (p -> end_of_root == true)
                return;
        }
        p -> end_of_root = true;
    }

    string replace(const string &s, int st, int ed) {
        Node *p = rt;
        for (int i = st; i <= ed; i++) {
            if (p -> nxt[s[i] - 'a'] == NULL)
                break;
            p = p -> nxt[s[i] - 'a'];
            if (p -> end_of_root == true)
                return s.substr(st, i - st + 1);
        }
        return s.substr(st, ed - st + 1);
    }

    string replaceWords(vector<string>& dict, string sentence) {
        for (string &s : dict)
            insert(s);

        string ans = "";
        int l = sentence.length(), last = 0;
        for (int i = 0; i < l; i++)
            if (sentence[i] == ' ') {
                ans += replace(sentence, last, i - 1) + " ";
                last = i + 1;
            }

        return ans + replace(sentence, last, l - 1);
    }
};