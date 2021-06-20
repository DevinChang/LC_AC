class Solution {
public:
	int get(string s) {
		int h, m;
		sscanf(s.c_str(), "%d:%d", &h, &m);
		return h * 60 + m;
	}
    int numberOfRounds(string startTime, string finishTime) {
		int x = get(startTime), y = get(finishTime);
		if(x > y) y += 24 * 60;
		x = (x + 14) / 15, y /= 15;
		return y - x;
    }
};