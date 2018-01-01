#include <vector>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define ERRORCODE -99999999.9999999



/*
sample 25 ms submission
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        if (total & 0x1)
            return find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
        else
            return (find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1) + find_kth(nums1.begin(), m, nums2.begin(), n, total / 2))/ 2.0;
    }
private:
    static int find_kth(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k){
        if (m > n) return find_kth(B, n, A, m, k);
        if (m == 0) return *(B + k - 1);
        if (k == 1) return min(*A, *B);
        
        int ia = min(k/2, m), ib = k - ia;
        if (*(A + ia - 1) < *(B + ib - 1))
            return find_kth(A + ia, m - ia, B, n, k - ia);
        else if (*(A + ia - 1) > *(B + ib - 1))
            return find_kth(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];
    }
};
*/

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2){
	
	if (nums1.size() > nums2.size())
		return findMedianSortedArrays(nums2, nums1);
	int m = nums1.size(), n = nums2.size();
	int imin = 0, imax = m;
	while (imin <= imax){
		int i = (imin + imax) >> 1, j = (n + m + 1) / 2 - i;
		
		
		if (i < imax && nums2[j - 1] > nums1[i])
			++imin;
		else if (i > imin && nums1[i - 1] > nums2[j])
			--imax;
		else{
			double maxleft = 0, minright = 0;
			if (i == 0)
				maxleft = nums2[j - 1];
			else if (j == 0)
				maxleft = nums1[i - 1];
			else
				maxleft = max(nums1[i - 1], nums2[j - 1]);
			if (i == m)
				minright = nums2[j];
			else if (j == n)
				minright = nums1[i];
			else
				minright = min(nums1[i], nums2[j]);
			if ((n + m) % 2)
				return maxleft;
			else
				return (maxleft + minright) / 2;
		}
	}
	return ERRORCODE;
}





