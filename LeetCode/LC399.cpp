class Solution {
public:
    unordered_map<string, string> parents; // 存储当前结点的父母
    unordered_map<string, double> weights; // 存储 当前结点值/父母值 的结果

    // 返回root以及从a/root的值
    pair <string, double> MyFind(string a){
        if(parents.find(a) == parents.end())
            return {"", -1.0};
        double result = 1.0;
        while(a != parents[a]){
            result *= weights[a]; // result *= a/parent;
            // 路径压缩后还需要更新weights，这里偷懒就不路径压缩了
            a = parents[a];
        }
        return {a, result}; // 返回a的根节点，和a/root的结果
    }
 
    // a_b表示a除以b的结果
    void MyUnion(string a, string b, double a_b){
        pair<string, double> p1 = MyFind(a);
        pair<string, double> p2 = MyFind(b);
        if("" == p1.first || "" == p2.first) return;
        if(p1.first == p2.first) return;
        parents[p1.first] = p2.first; 
        weights[p1.first] = 1/p1.second * a_b * p2.second; // 更新权重
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 并
        for(int i=0; i<equations.size(); ++i){
            string a = equations[i][0];
            string b = equations[i][1];
            // 并查集初始化
            if(parents.find(a) == parents.end()){
                parents[a] = a;
                weights[a] = 1.0;
            }
            if(parents.find(b) == parents.end()){
                parents[b] = b;
                weights[b] = 1.0;
            }
            // 并操作
            MyUnion(a, b, values[i]);
        }

        // 查
        vector<double> result;
        for(auto &q : queries){
            string a = q[0];
            string b = q[1];
            pair<string, double> p1 = MyFind(a); // p1.second = a/p1
            pair<string, double> p2 = MyFind(b); // p2.second = b/p2
            if(p1.first != p2.first || "" == p1.first || "" == p2.first){
                result.push_back(-1.0);
            }
            else{
                result.push_back(p1.second/p2.second); // a/b = (a/p1) / (b/p2);
            }
        }
        return result;

    }


    vector<double> calcEquation_folloid(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> vers;
        unordered_map<string, unordered_map<string,double>> d;
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            auto a = equations[i][0], b = equations[i][1];
            auto c = values[i];
            d[a][b] = c, d[b][a] = 1 / c;
            vers.insert(a), vers.insert(b);
        }
        for(auto k : vers) {
            for(auto i : vers) {
                for(auto j : vers) {
                    if(d[i][k] && d[j][k]) d[i][j] = d[i][k] * d[k][j];
                }
            }
        }
        vector<double> res;
        for(auto q : queries) {
            auto a = q[0], b = q[1];
            if(d[a][b]) res.push_back(d[a][b]);
            else res.push_back(-1);
        }
        return res;
    }
};