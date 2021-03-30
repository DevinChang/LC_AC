class Solution {
public:
    vector<int> p;
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.resize(n+1);
        for(int i = 1; i <= n; i++) p[i] = i;
        for(auto &e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if(a != b) p[a] = b;
            else return e;
        }
        return {};
    }
};