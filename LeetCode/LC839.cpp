class Solution {
public:
    int n;
    vector<int> p;
    
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool check(string& a, string& b){
        if(a == b)return true;
        vector<int> q;
        for(int i = 0; i <a.size(); i++){
            if(a[i] != b[i]) q.push_back(i);
        }
        if(q.size() != 2) return false;
        int x = q[0], y = q[1];
        return a[x] == b[y] && a[y] == b[x];
    }

    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
        int res = n;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(check(strs[i], strs[j])){
                    if(find(i) != find(j)){
                        p[find(i)] = find(j);
                        res--;
                    }
                }
            }
        }
        return res;
    }
};