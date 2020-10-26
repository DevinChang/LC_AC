
bool isAnagram(string s, string t) {
    unordered_map<int, int> hash;
    for(auto c : s) hash[c-'a']++;
    for(auto c : t) hash[c-'a']--;
    for(int i = 0; i < 26; i ++){
        if(hash[i] != 0) return false;
    }
    return true;
}