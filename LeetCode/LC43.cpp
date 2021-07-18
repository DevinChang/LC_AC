class Solution {
public:
    string multiply(string num1, string num2) {
		int n = num1.size(), m = num2.size();
		vector<int> A, B;
		vector<int> C(n + m);
		for(int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0');
		for(int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) 
				C[i+j] += A[i] * B[j];
		}
        
		for(int i = 0, t = 0; i < n + m; i++) {
			t += C[i];
			C[i] = t % 10;
			t /= 10;
		} 

		int k = n + m - 1;
		while(k > 0 && !C[k]) k--;
        
		string res;
		while(k >= 0) res += C[k--] + '0';
		return res;
    }
};