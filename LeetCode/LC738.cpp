class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int k = 0, n = str.size();
        while(k+1 < n && str[k] <= str[k+1])k++;
        if(k == n-1) return N;
        while(k && str[k-1] == str[k]) k--;
        str[k]--;
        for(int i = k+1; i < n; i++) str[i] = '9';
        return stoi(str);
    }
};