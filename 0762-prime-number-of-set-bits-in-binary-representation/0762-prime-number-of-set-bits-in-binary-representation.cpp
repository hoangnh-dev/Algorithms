class Solution {
private:
int countSetBits(int num){
    int count = 0;
    while (num > 0) {
        count++;
        num &= (num - 1);
    }
    return count;
}
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            int setBits = countSetBits(i);
            if (isPrime(setBits)) count++;
        }
        return count;
    }
};