class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > sx && ty > sy) {
            if(tx < ty) ty %= tx;
            else tx %= ty;
        }
        if(tx < sx || ty < sy) return false;
        if(sx == tx) return (ty-sy) % sx == 0;
        return (tx-sx) % sy == 0;
    }
};