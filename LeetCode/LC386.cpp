class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++) dfs(i, n);
        return res;
    }

    void dfs(int c , int n){
        if(c <= n) res.push_back(c);
        else return;
        for(int i = 0; i <= 9; i++){
            dfs(c* 10 + i, n);
        }
    }
};