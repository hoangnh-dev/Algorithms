typedef struct {
    int r;
    int c;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    Point queue[200];
    int front = 0;
    int rear = 0;
    int time = 0;
    int cols = gridColSize[0];
    int countFresh = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for(int i = 0; i < gridSize; i ++){
        for(int j = 0; j < cols; j ++){
            if(grid[i][j] == 2) queue[rear++] = (Point){i,j};
            else if(grid[i][j] == 1) countFresh++;
        }
    }
    if (countFresh == 0) return 0;
    while (front < rear) {
        int currSize = rear - front;
        for(int i = 0; i < currSize; i ++){
            Point curr = queue[front++];
            for (int j = 0; j < 4; j++) {
                int nr = curr.r + dr[j];
                int nc = curr.c + dc[j];
                if (nr >= 0 && nr < gridSize && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear++] = (Point){nr, nc};
                    countFresh--;
                }
            }
        }
        time++;
        if (countFresh == 0) break;
    }
    if (countFresh > 0) return -1;
    else return time;
}