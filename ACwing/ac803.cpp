#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;


int merge_segs(vector<PII> &segs) {
	vector<PII> res;
	sort(segs.begin(), segs.end());
	int st = -2e9, ed = -2e9;
	for(auto seg : segs) {
		if(ed < seg.first) {
			if(st != -2e9) res.push_back({st, ed});
			st = seg.first, ed = seg.second;
		} else {
			ed = max(seg.second, ed);
		}
	}
	if(ed != -2e9) res.push_back({st, ed});
	return res.size();
}

int main() {
	int n;
	cin >> n;
	vector<PII> segs;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}
	cout << merge_segs(segs) << endl;
	return 0;
}