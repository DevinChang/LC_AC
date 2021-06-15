class Solution {
public:
    bool isLongPressedName(string name, string typed) {
		int i = 0, j = 0;
		int n = name.size(), m = typed.size();
		while(i < n && j < m) {
			if(name[i] != typed[j]) return false;
			int x = i + 1, y = j + 1;
			while(x < n && name[x] == name[i]) x++;
			while(y < m && typed[y] == typed[j]) y++;
			if(x - i > y - j) return false;
			i = x, j = y;
		}
		return i == n && j == m;
    }
};