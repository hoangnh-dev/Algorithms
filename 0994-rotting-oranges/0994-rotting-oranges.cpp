class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time = 0;
        int freshCount = 0;
        int rSize = grid.size();
        int cSize = grid[0].size();
        array<pair<int,int>, 4> dirs = {{{-1,0},{1,0},{0,-1},{0,1}}};
        for(int i = 0; i < rSize; i ++){
            for(int j = 0; j < cSize; j ++){
                if (grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) freshCount++;
            }
        }
        if(freshCount ==0)return 0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr>=0 && nr<rSize && nc >= 0 && nc< cSize &&  grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        freshCount--;
                    }
                }
            }
            time++;
            if (freshCount == 0) break;
        }
        if(freshCount > 0) return - 1;
        else return time;
    }
};