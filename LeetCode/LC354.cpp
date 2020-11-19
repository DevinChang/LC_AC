class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end());
        vector<int> f(n);
        int ret = 0;
        for(int i = 0; i < n; i++){
            f[i] = 1;
            for(int j = 0; j < i; j++){
                if(e[j][0] < e[i][0] && e[j][1] < e[i][1]){
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            ret = max(ret, f[i]);
        }
        return ret;
    }
};



static bool cmp(vector<int> &A,vector<int> &B)
{
    return (A[0] == B[0])?A[1] > B[1] : A[0] < B[0];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    if(n == 0) return 0;
    sort(envelopes.begin(),envelopes.end(),cmp);
    vector<int> dp;//dp[i]存储的是长度为i的最长递增子序列的第i个元素(这个元素越靠前越好)
    for(int i = 0 ; i < n ; i ++)
    {
        int left = 0, right = dp.size();
        int temp = envelopes[i][1];
        //找到递增子序列末尾元素小于当前信封长度的最大长度。
        while(left < right){
            int mid = (left + right) / 2;
            if(dp[mid] >= temp)
                right = mid;
            else
                left = mid + 1;
        }
        //如果所有当前所有递增子序列的末尾元素都小于当前信封高度，说明找到了一个新的更长的递增子序列。
        if(right == dp.size())
            dp.push_back(temp);
        else
            dp[right] = temp;
    }
    return dp.size();
}