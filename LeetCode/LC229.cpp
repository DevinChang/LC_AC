
vector<int> majorityElement_hash(vector<int> &nums) {
    int n = nums.size();
    int limit = n / 3;
    unordered_map<int, int> hash;
    set<int> s;
    for(auto num : nums) {
        if(hash[num]++ > limit){
            s.insert(num);
        }
    }
    return vector<int>(s.begin(), s.end());
}

vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();
    int candidate1 = 0;
    int candidate2 = 0;
    int count1 = 0;
    int count2 = 0;
    for(auto i : nums){
        if(i == candidate1) count1++;
        else if(i == candidate2) count2++;
        else if(count1 == 0) candidate1 = i,count1 = 1;
        else if(count2 == 0) candidate2 = i,count2 = 1;
        else count1--, count2--;
    }
    count1 = count2 = 0;
    vector<int> ret;
    for(auto i : nums){
        if(candidate1 == i) count1++;
        else if (candidate2 == i) count2++;
    }
    if(count1 > n / 3) ret.push_back(candidate1);
    if(count2 > n / 3) ret.push_back(candidate2);
    return ret;
}