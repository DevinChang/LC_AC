class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int m) {
        int n = hand.size();
        if(n % m != 0) return false; 
        multiset<int> S;
        for(auto x :hand) S.insert(x);
        while(S.size()){
            int x = *S.begin();
            for(int i = x; i < x + m; i++){
                if(!S.count(i)) return false;
                else S.erase(S.find(i));
            }
        }
        return true;
    }
};