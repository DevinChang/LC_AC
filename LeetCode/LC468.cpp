class Solution {
public:

    string checkIPv4(string ip) {
        stringstream ss(ip+".");
        vector<string> items;
        string s;
        while(getline(ss, s, '.')) items.push_back(s);
        if(items.size() != 4) return "Neither";
        for(auto item : items) {
            if(item.empty() || item.size() > 3) return "Neither";
            if(item.size() > 1 && item[0] == '0') return "Neither";
            for(auto c : item){
                if(c < '0' || c > '9') return "Neither";
            }
            int t = stoi(item);
            if(t > 255) return "Neither";
        }
        return "IPv4";
    }


    bool check(char c) {
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c <= 'f') return true;
        if (c >= 'A' && c <= 'F') return true;
        return false;
    }

    string checkIPv6(string ip) {
        stringstream ss(ip+":");
        vector<string> items;
        string s;
        while(getline(ss, s, ':')) { 
            items.push_back(s); 
            cout << s << endl;
        }
        cout << items.size() << endl;
        if(items.size() != 8) return "Neither";
        for(auto item : items) {
            if(item.empty() || item.size() > 4) return "Neither";
            for(auto c : item) {
                if(!check(c)) return "Neither";
            }
        }
        return "IPv6";
    }


    string validIPAddress(string IP) {
        if(IP.find('.') != -1 && IP.find(':') != -1) return "Neither";
        if(IP.find('.') != -1) return checkIPv4(IP);
        if(IP.find(':') != -1) return checkIPv6(IP);
        return "Neither";
    }
};