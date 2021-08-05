#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	string s;
	int k;
	cin >> s >> k;
	string res = "0";
	for(int i = 0; i < s.size(); i++) {
		while(k && s[i] < res.back()) {
			res.pop_back();
			k--;
		}
		res += s[i];
	}
	while(k--) res.pop_back();
	int i = 0;
	while(i < res.size() && res[i] == '0') i++;
	if(i == res.size()) puts("0");
	else cout << res.substr(i) << endl;
	return 0;
}