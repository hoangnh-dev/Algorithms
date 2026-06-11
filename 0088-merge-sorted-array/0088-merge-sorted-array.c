void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int num1EleIndex = m - 1;
    int num1Index = nums1Size - 1;
    int nums2Index = n - 1;

    while(nums2Index >= 0){
        if (num1EleIndex >= 0 && nums1[num1EleIndex] > nums2[nums2Index]){
            nums1[num1Index--] = nums1[num1EleIndex--];
        }else{
            nums1[num1Index--] = nums2[nums2Index--];
        }
    }
}