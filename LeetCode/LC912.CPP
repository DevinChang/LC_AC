class Solution {
public:
    void quick_sort(vector<int>& q, int l, int r) {
	if(l >= r) return;
	int i = l - 1, j = r + 1, x = q[l+r >> 1];
	while(i < j) {
	    do i++; while(q[i] < x);
	    do j--; while(q[j] > x);
	    if(i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
	quick_sort(nums, 0, nums.size()-1);
	return nums;
    }
};