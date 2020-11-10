class Solution {
public:
    
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(i * 2 + 1) % (n | 1)]
        int n = nums.size();
        auto midptr = nums.begin() +  n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        for(int i = 0, j = 0, k = n-1; i <= k;){
            if(A(i) > mid) swap(A(i++), A(j++));
            else if(A(i) < mid) swap(A(i), A(k--));
            else i++;
        }
    }
};