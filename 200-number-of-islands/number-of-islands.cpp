class Solution {
public:
    int dr[4] = {1, -1 , 0 , 0};
    int dc[4] = {0 , 0, 1, -1};
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    bfs(i , j , grid);
                }
            }
        }
        return islands;
    }
    void bfs(int st , int end ,vector<vector<char>>&grid) {
        int m = grid.size();
        int n = grid[0].size();
        grid[st][end] = '0';
        queue<pair<int ,int>>q;
        q.push({st , end});
        while(!q.empty()) {
            auto [r , c] = q.front();
            q.pop();
            for(int i = 0;i < 4;i++) {
                for(int j = 0;j < 4;j++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nc >= 0 && nr >= 0 && nr < m && nc < n) {
                        if(grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            q.push({nr , nc});
                        }
                    }
                }
            }
        }
    }
};