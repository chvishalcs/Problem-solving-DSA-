class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int dirs[5] = {1, 0, -1, 0, 1};

        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int t = top[0], r = top[1], c = top[2];
            if(r == n - 1 && c == n - 1) return t;
            if(vis[r][c]) continue;
            vis[r][c] = 1;
            for(int k = 0; k < 4; k++){
                int x = r + dirs[k], y = c + dirs[k + 1];
                if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y]) continue;
                pq.push({max(t, grid[x][y]), x, y});
            }
        }
        return -1;
    }
};