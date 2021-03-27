class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        for(int i = 0; i+1 < str.size(); i++) {
            if(str[i] < str[i+1]) {
                int k = i + 1;
                for(int j = k; j < str.size(); j++) {
                    if(str[j] >= str[k]) k = j;
                }
                for(int i = 0; ;i++) {
                    if(str[i] < str[k]){
                        swap(str[i], str[k]);
                        return stoi(str);
                    } 
                }
            }
        }
        return num;
    }
};