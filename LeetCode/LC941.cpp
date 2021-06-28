class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
		int k = 0, n = arr.size();
		while(k + 1 < n && arr[k] < arr[k+1]) k++;
		if(k+1 == n || k == 0) return false;
		while(k + 1 < n && arr[k] > arr[k+1]) k++;
		return k + 1 == n;
    }
};