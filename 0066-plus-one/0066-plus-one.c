/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int index = digitsSize -1;
    while(index >= 0){
        if (digits[index]  < 9){
            digits[index]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[index--] = 0;
    }
    *returnSize = digitsSize + 1;
    int* result = malloc(*returnSize* sizeof(int));
    result[0] = 1;
    for(int i = 1; i < *returnSize; i++){
        result[i] = 0;
    }
    return result;
}