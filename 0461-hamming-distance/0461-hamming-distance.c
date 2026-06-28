int hammingDistance(int x, int y) {
    int result = 0;
    int z = x^y;
    while(z > 0){
        z &= (z - 1);
        result++;
    }
    return result;
}