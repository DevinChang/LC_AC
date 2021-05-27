class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> id(n);
        for(int i = 0; i < n; i++){
            id[i] = i;
        }
        sort(id.begin(), id.end(), [&](int x, int y) {
            return nums2[x] < nums2[y];
        });
        vector<int> res(n);
        int l = 0, r = n - 1;
        for(int i = 0; i < n; i++){
            if(nums1[i] > nums2[id[l]]) res[id[l++]] = nums1[i];
            else {
                res[id[r--]] = nums1[i];
            }
        }
        return res;
    }
};