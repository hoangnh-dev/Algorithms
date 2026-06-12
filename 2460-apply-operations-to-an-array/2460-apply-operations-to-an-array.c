/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    int* result = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    int index = 0;
    for (int i = 0; i < numsSize ; i++){
        if (nums[i] == 0) continue;
        if ( i < numsSize - 1 && nums[i] == nums[i+1]){
            result[index] += nums[i]*2;
            i++;
        }else{
            result[index] = nums[i];
        }
        index++;
    }
    return result;
}