

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> hash;
    for(auto a : nums){
        hash[a]++;
        if(hash[a] > 1) return true;
    }
    return false;
}