class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNegative = (dividend < 0) != (divisor < 0);
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long result = 0;
        while(absDividend >= absDivisor){
            int i = 0;
            while ((absDivisor << (i + 1)) <= absDividend) i++;
            absDividend -= (absDivisor << i);
            result += (1LL << i);
        }
        if(isNegative) return -result;
        return result;
    }
};