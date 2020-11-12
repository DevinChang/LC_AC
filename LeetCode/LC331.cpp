class Solution {
public:
    string s;
    int k;

    bool isValidSerialization(string preorder) {
        s = preorder + ',';
        k = 0;
        if(!dfs()) return false;
        return k == s.size();
    }

    bool dfs(){
        if(k == s.size()) return false; // 该判定表示k遍历到字符最后，而序列已经没有值的情况下，不合法
        // 当前的节点为空，需要略过去#和逗号，注意这个是正常返回，合法的，所有要返回true
        if(s[k] == '#'){
            k += 2;
            return true;
        }
        while(s[k] != ',') k++;
        k++; // 跳过逗号
        return dfs() && dfs(); // 再判断左右子树是否合法
    }
};