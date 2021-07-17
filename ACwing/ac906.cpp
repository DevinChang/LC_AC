#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;



int main() {
	int n;
	cin >> n;
	vector<PII> range;
	for(int i = 0; i < n; i++) {
		int l, r; 
		cin >> l >> r;
		range.push_back({l, r});
	}
	sort(range.begin(), range.end(), [&](PII a, PII b) {
		return a.second < b.second;
	});
	int res = 0, ed = -2e9;
	for(auto &r : range) {
		if(r.first > ed) {
			res++;
			ed = r.second;
		}
	}
	cout << res << endl;
	return 0;
}