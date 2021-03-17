class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hash;
        for (auto& path: paths) {
            // 这里用stringstream按照空格隔开读入
            stringstream ssin(path);
            // p是最开头的目录，file是文件名加内容的一整段，name是文件名部分，content是目录部分
            string p, file, name, content;
            ssin >> p;
            while (ssin >> file) {
                // 对于每个文件找到左括号和右括号的位置就能切分文件名和文件内容了
                int lp = file.find('('), rp = file.find(')');
                name = file.substr(0, lp), content = file.substr(lp + 1, rp - lp - 1);
                // 在哈希表里按照内容放入"路径/文件名"
                hash[content].push_back(p + '/' + name);
            }
        }
        // 找同一个内容有多个path的
        vector<vector<string>> res;
        for (auto& [k, v]: hash)
            if (v.size() > 1)
                res.push_back(v);
        return res;
    }
};
