class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0)), at1 = pac, res;
        int dirs[5] = {1, 0, -1, 0, 1};
        auto dfs = [&](auto&& self, int r, int c, vector<vector<int>>& vis) -> void {
            vis[r][c] = 1;
            for(int k = 0; k < 4; k++){
                int x = r + dirs[k], y = c + dirs[k + 1];
                if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y] || heights[x][y] < heights[r][c])
                continue;
                self(self, x, y, vis);
            }
        };
        for(int i = 0; i < m; i++) dfs(dfs, i, 0, pac), dfs(dfs, i, n - 1, at1);
        for(int j = 0; j < n; j++) dfs(dfs, 0, j, pac), dfs(dfs, m - 1, j, at1);
        for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
        if(pac[i][j] && at1[i][j]) res.push_back({i, j});
        return res;
    }
};