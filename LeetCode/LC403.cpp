int f[1200][1200];
class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> stones;

    int dp(int i , int j){
        if(f[i][j] != -1) return f[i][j];
        f[i][j] = 0;
        for(int k = max(1, j-1); k <= j+1; k++){
            if(hash.count(stones[i]-k)) {
                int p = hash[stones[i]-k];
                if(dp(p, k)) {
                    f[i][j] = 1;
                    break;
                }
            }
        }
        return f[i][j];
    }

    bool canCross_dfs(vector<int>& _stones) {
        stones = _stones;
        int n = _stones.size();
        for(int i = 0; i < n; i++) hash[stones[i]] = i;
        memset(f, -1, sizeof f);
        f[0][1] = 1;
        for(int i = 0; i < n; i++){
            // 深度优先搜索
            if(dp(n-1, i)) return true;
        }
        return false;
    }

    bool canCross(vector<int>& _stones) {
        stones = _stones;
        int n = stones.size();
        unordered_map<int, int> h;

        for (int i = 0; i < n; i++)
            h[stones[i]] = i;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vis[0][0] = true;
        q.push(make_pair(0, 0));

        while (!q.empty()) {
            auto sta = q.front();
            q.pop();
            int cur_x = sta.first, cur_k = sta.second;

            if (cur_x == n - 1)
                return true;

            for (int i = -1; i <= 1; i++) {
                if (cur_k + i <= 0)
                    continue;
                int next_k = cur_k + i;
                int next_p = stones[cur_x] + next_k;
                if (h.find(next_p) != h.end()) {
                    int next_x = h[next_p];
                    if (!vis[next_x][next_k]) {
                        vis[next_x][next_k] = true;
                        q.push(make_pair(next_x, next_k));
                    }
                }
            }
        }

        return false;
    }
};