class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size(), m = image[0].size();
        for(int i = 0; i < n; i++) {
            reverse(image[i].begin(), image[i].end());
            for(int j = 0; j < m; j++) image[i][j] ^= 1;
        }
        return image;
    }
};