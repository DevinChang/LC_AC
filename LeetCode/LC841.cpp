class Solution {
public:
    vector<vector<int>> g;
    vector<bool> st;
    int n;

    void dfs(int u){
        st[u] = true;
        for(auto v : g[u]){
            if(!st[v]) dfs(v);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        g = rooms;
        n = rooms.size();
        st.resize(n);
        dfs(0);
        for(int i = 0; i < n; i++) {
            if(!st[i]) return false;
        }
        return true;
    }
};