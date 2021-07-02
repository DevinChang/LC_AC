class Solution {
public:
	bool check(vector<int>& arr, int t) {
		map<int, int> hash;
		for(auto x : arr) {
			if(x * t > 0) {
				hash[x*t]++;
			}
		}
		while(hash.size()){
			auto it = hash.begin();
			auto x = it->first, y = it->second;
			if(hash[x] == 0) {
				hash.erase(it);
			} 
			else {
				if(hash[x * 2] == 0) {
					cout << x << " " << x * 2 << endl;
					return false;
				}
				hash[x*2]--;
				hash[x]--;
			}
		}
		return true;
	}
    bool canReorderDoubled(vector<int>& arr) {
		return check(arr, 1) && check(arr, -1);
    }
};