
class Solution {
public:
    int n = 20001;
    vector<int> tr;
    int lowbit(int x){
        return x & -x;
    }

    int query(int x){
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    void add(int x, int v){
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += v;
    }
    vector<int> countSmaller(vector<int>& nums) {
        tr.resize(n+1);
        int len = nums.size();
        vector<int> res(len);
        for(int i = len - 1; i >= 0; i--){
            int x = nums[i] + 10001;
            res[i] = query(x-1);
            add(x, 1);
        }
        return res;
    }
};