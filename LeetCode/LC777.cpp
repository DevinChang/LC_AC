class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while(1) {
            while(i < n && start[i] == 'X') i++;
            while(j < n && end[j] == 'X') j++;
            if(i == n || j == n) break;
            if(start[i] != end[j]) return false;
            if(start[i] == 'L' && i < j) return false;
            if(end[j] == 'R' && j < i) return false;
            i++, j++;
        }
        return i == n && j == n;
    }
};