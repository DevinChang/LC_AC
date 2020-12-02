class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26, 0);
        for(auto c : magazine) {
            hash[c - 'a']++;
        }
        for(auto c : ransomNote){
            if(hash[c-'a'] == 0) return false;
            hash[c-'a']--;
        }
        return true;
    }
};