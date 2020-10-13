
vector<vector<int>> ret;
vector<int> path;

vector<vector<int>> combinationSum3(int k, int n){
    dfs(k, n, 1);
    return ret;
}

void dfs(int k, int n, int st) {
    if(!k){
        if(!n){
            ret.push_back(path);
            return;
        }
    }
    for(int i = st; i <= 10-k; i++){
        if(n >= i){
            path.push_back(i);
            dfs(k-1, n-i, i+1);
            path.pop_back();
        }
    }
}

