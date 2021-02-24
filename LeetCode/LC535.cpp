class Solution {
public:
    unordered_map<string, string> hash;
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string prefix = "http://tinyurl.com/";

    string random_str(int k ) {
        string res;
        while(k--) res += chars[rand() % 62];
        return res;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (true) {
            string shortUrl = random_str(6);
            if (hash.count(shortUrl) == 0) {
                hash[shortUrl] = longUrl;
                return prefix + shortUrl;
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[shortUrl.substr(19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));