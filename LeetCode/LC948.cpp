class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
		int n = tokens.size(), res = 0, grade = 0;
		sort(tokens.begin(), tokens.end());
		for(int i = 0, j = n-1; i <= j; ) {
			while(i <= j && power >= tokens[i]) {
				power -= tokens[i++];
				grade++;
			}
			res = max(res, grade);
			if(grade > 0 && i <= j) {
				power += tokens[j--];
				grade--;
			} else {
				break;
			}
		}
		return res;
    }
};