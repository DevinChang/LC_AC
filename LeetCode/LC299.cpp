class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> hash(10, 0);
        int bulls = 0, crows = 0;
        int n = secret.size();
        for(int i = 0; i < n; i++){
            hash[secret[i] - '0']++;
            if(secret[i] == guess[i]) bulls++;
        }
        for(int i = 0; i < n; i++){
            if(hash[guess[i]-'0'] > 0){
                crows++;
                hash[guess[i]-'0']--;
            }
        }
        return to_string(bulls)+"A" + to_string(crows-bulls)+"B";
    }
};