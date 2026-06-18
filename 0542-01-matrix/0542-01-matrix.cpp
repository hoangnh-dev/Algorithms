class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int distance = 1;
        int rSize = mat.size();
        int cSize = mat[0].size();
        array<pair<int,int>, 4> dirs = {{{-1,0},{1,0},{0,-1},{0,1}}};
        for(int i = 0; i < rSize; i ++){
            for(int j = 0; j < cSize; j ++){
                if (mat[i][j] == 0) q.push({i, j});
                else if(mat[i][j] == 1) mat[i][j] = -1;
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i =0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr>=0 && nr<rSize && nc >= 0 && nc< cSize &&  mat[nr][nc] == -1){
                        q.push({nr, nc});
                        mat[nr][nc] = distance;
                    }
                }
            }
            distance++;
        }
        return mat;
    }
};