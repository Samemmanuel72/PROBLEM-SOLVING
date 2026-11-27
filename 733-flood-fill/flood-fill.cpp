class Solution {
public:
int dr[4] = {1, -1 ,0 ,0};
int dc[4] = {0 ,0 , -1 , 1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int rtx = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int , int>>q;
        q.push({sr, sc});
        while(!q.empty()) {
            auto [x , y] = q.front();
            q.pop();
            
                for(int j = 0;j < 4;j++) {
                    int nr = x + dr[j];
                    int nc = y + dc[j];
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n) {
                        if(image[nr][nc] != color && image[nr][nc] == rtx)  {
                            image[nr][nc] = color;
                            q.push({nr , nc});
                        }
                    }
                
            }
        }
        return image;
    }
};