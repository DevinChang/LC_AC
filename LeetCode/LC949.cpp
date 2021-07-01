class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		string res;
		do {
			auto h = to_string(arr[0]) + to_string(arr[1]);
			auto m = to_string(arr[2]) + to_string(arr[3]);
			auto t = h + ':' + m;
			if(h <= "23" && m <= "59") {
				if(res.empty() || res < t) res = t;
			}
		} while(next_permutation(arr.begin(), arr.end()));
		return res;
    }
};