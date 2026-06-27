/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int subSize = 1<<numsSize;
    int** subs = malloc(subSize*sizeof(int*));
    *returnSize = subSize;
    *returnColumnSizes = malloc(subSize * sizeof(int));
    for(int i = 0; i < subSize; i++) {
        int temp = i;
        int* sub = malloc(numsSize*sizeof(int));
        int index = 0;
        for(int j = 0; j < numsSize; j++) {
            if (temp & 1) {
                sub[index++] = nums[j];
            }
            temp >>= 1;
        }
        (*returnColumnSizes)[i] = index;
        subs[i] = sub;
    }
    return subs;
}