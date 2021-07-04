#include <iostream>
using namespace std;


const int N = 1000010;
int n;
int arr[N], q[N];



int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	int len = 0;
	for(int i = 1; i <= n; i++) {
		int l = 0, r = len;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(q[mid] < arr[i]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		q[r+1] = arr[i];
	}

	cout << len << endl;

	return 0;
}