typedef struct {
    int r;
    int c;
} Point;
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    if(grid[0][0] == 1) return -1;
    if(gridSize == 1) return 1;
    int n = gridSize;
    Point queue[n*n];
    int front = 0;
    int rear = 0;
    int distance = 1;
    queue[rear++] = (Point){0,0};
    grid[0][0] = 1;
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (front < rear) {
        int currSize = rear - front;
        for(int i = 0; i < currSize; i ++){
            Point curr = queue[front++];
            if (curr.r == n-1 && curr.c == n-1) return distance;
            for (int j = 0; j < 8; j++) {
                int nr = curr.r + dr[j];
                int nc = curr.c + dc[j];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    queue[rear++] = (Point){nr, nc};
                }
            }
        }
        distance++;
    }
    return -1;
}