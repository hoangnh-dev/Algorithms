int find(int* root,int x) {
    if (root[x] != x) root[x] = find(root, root[x]);
    return root[x];
}
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int root[n];
    for (int i = 0; i < n; i++) root[i] = i;

    for (int i = 0; i < edgesSize; i++) {
        int p1 = find(root, edges[i][0]);
        int p2 = find(root, edges[i][1]);
        if (p1 != p2) root[p1] = p2;
    }
    return find(root, source) == find(root, destination);
}