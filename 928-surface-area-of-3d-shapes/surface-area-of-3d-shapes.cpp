class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                int h = grid[i][j];
                if(h > 0){
                    area += 6 * h;
                    area -= 2 * (h - 1);
                }
                if(i > 0){
                    area -= 2 * min(h, grid[i - 1][j]);
                }
                if(j > 0){
                    area -= 2 * min(h, grid[i][j - 1]);
                }
            }
        }
        return area;
    }
};