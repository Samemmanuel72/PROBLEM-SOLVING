class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        grid[r][c] = 0;

        int cnt = 1;

 
        for(int j = 0; j < m; j++) {

            if(grid[r][j] == 1) {
                cnt += dfs(r, j, grid);
            }
        }

        for(int i = 0; i < n; i++) {

            if(grid[i][c] == 1) {
                cnt += dfs(i, c, grid);
            }
        }

        return cnt;
    }

    int countServers(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    int cnt = dfs(i, j, grid);

                    if(cnt > 1) {
                        ans += cnt;
                    }
                }
            }
        }

        return ans;
    }
};