void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void minHeap(int* arr, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&arr[idx], &arr[smallest]);
        minHeap(arr, size, smallest);
    }
}
int findKthLargest(int* nums, int numsSize, int k) {
    int arr[k];
    for (int i = 0; i < k; i++) {
        arr[i] = nums[i];
    }
    for (int i = (k / 2) - 1; i >= 0; i--) {
        minHeap(arr, k, i);
    }
    for (int i = k; i < numsSize; i++) {
        if (nums[i] > arr[0]) {
            arr[0] = nums[i]; 
            minHeap(arr, k, 0);
        }
    }
    return arr[0];
}