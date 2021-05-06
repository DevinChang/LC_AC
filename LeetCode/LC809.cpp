class Solution {
public:
    int getNext(const string& a, int st) {
        int len = 0;
        for(int i = st; i < a.size(); i++) {
            if(a[i] == a[st]) len++;
            else break;
        }
        return len;
    }
    bool check(const string& a, const string& b) {
        const int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(a[i] != b[j]) return false;
            int l1 = getNext(a, i);
            int l2 = getNext(b, j);
            if(!(l1 == l2 || (l1 < l2 && l2 >= 3))) return false;
            i += l1;
            j += l2;
        }
        return i == n && j == m;
    }
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for(auto &w : words) {
            if(check(w, S)) res++;
        }
        return res;
    }
};