


string largesNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int x, int y){
        string a = to_string(x), b = to_string(y);
        return a + b > b + a;
    });
    string res;
    for(auto n : nums) res += to_string(n);
    int k = 0, n = nums.size();
    while(k+1 < n && res[k] == '0') k++;
    return res.substr(k);
}