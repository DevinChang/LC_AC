class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> cnt;
        for(auto& str : cpdomains) {
            int k = str.find(' ');
            int c = stoi(str.substr(0, k));
            str = str.substr(k+1);
            while(true) { 
                cnt[str] += c;
                k = str.find('.');
                if(k == -1) break;
                str = str.substr(k+1);
            }
        }
        vector<string> res;
        for(auto& [k,v] : cnt) res.push_back(to_string(v) + ' ' + k);
        return res;
    }
};