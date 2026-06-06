/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define HASH_SIZE 100000
 #define HEAP_SIZE 100000

 typedef struct {
    int key;   
    int count;
} DeleteEntry;
typedef struct {
    int data[HEAP_SIZE];
    int size;
} Heap;


DeleteEntry checkList[HASH_SIZE];
Heap max_heap;
Heap min_heap;

void hash_init() {
    memset(checkList, 0, sizeof(checkList));
}

int hash_func(int value) {
    int id = value % HASH_SIZE;
    if (id < 0) id += HASH_SIZE;
    return id;
}
void hash_add(int value) {
    int id = hash_func(value);
    while (checkList[id].count != 0 && checkList[id].key != value) {
        id = (id + 1) % HASH_SIZE;
    }
    checkList[id].key = value;
    checkList[id].count++; 
}
int hash_get(int value) {
    int id = hash_func(value);
    while (checkList[id].count != 0) {
        if (checkList[id].key == value) {
            return checkList[id].count;
        }
        id = (id + 1) % HASH_SIZE;
    }
    return 0;
}
void hash_remove(int value) {
    int id = hash_func(value);
    
    while (checkList[id].count != 0) {
        if (checkList[id].key == value) {
            if (checkList[id].count > 0) {
                checkList[id].count--;
            }
            return;
        }
        id = (id + 1) % HASH_SIZE;
    }
}

void max_heap_push(Heap* h, int val) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] >= val) break;
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = val;
}

int max_heap_pop(Heap* h) {
    int res = h->data[0];
    int val = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        if (child + 1 < h->size && h->data[child + 1] > h->data[child]) {
            child++;
        }
        if (val >= h->data[child]) break;
        h->data[i] = h->data[child];
        i = child;
    }
    h->data[i] = val;
    return res;
}

int max_heap_top(Heap* h) {
    return h->data[0];
}

void min_heap_push(Heap* h, int val) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] <= val) break;
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = val;
}

int min_heap_pop(Heap* h) {
    int res = h->data[0];
    int val = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        if (child + 1 < h->size && h->data[child + 1] < h->data[child]) {
            child++;
        }
        if (val <= h->data[child]) break;
        h->data[i] = h->data[child];
        i = child;
    }
    h->data[i] = val;
    return res;
}

int min_heap_top(Heap* h) {
    return h->data[0];
}

void clean_heap(Heap* h, int is_max) {
    while (h->size > 0) {
        int top = is_max ? max_heap_top(h) : min_heap_top(h);
        if (hash_get(top) > 0) {
            hash_remove(top); 
            if (is_max) max_heap_pop(h);
            else min_heap_pop(h);
        } else {
            break; 
        }
    }
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    double* result = (double*)malloc(*returnSize * sizeof(double));
    int max_size = 0; 
    int min_size = 0;

    hash_init();
    max_heap.size = 0;
    min_heap.size = 0;

    for (int i = 0; i < numsSize; i++) {
        if (max_size == 0 || nums[i] <= max_heap_top(&max_heap)) {
            max_heap_push(&max_heap, nums[i]);
            max_size++;
        } else {
            min_heap_push(&min_heap, nums[i]);
            min_size++;
        }

        
        if (i >= k) {
            int out_num = nums[i - k];
            
            if (max_size > 0 && out_num <= max_heap_top(&max_heap)) {
                hash_add(out_num); 
                clean_heap(&max_heap, 1);
                max_size--;
            } else {
                hash_add(out_num); 
                clean_heap(&min_heap, 0);
                min_size--;
            }
        }

        while (max_size > min_size + 1) {
            clean_heap(&max_heap, 1);
            int val = max_heap_pop(&max_heap);
            min_heap_push(&min_heap, val);
            max_size--;
            min_size++;
        }
        while (min_size > max_size) {
            clean_heap(&min_heap, 0);
            int val = min_heap_pop(&min_heap);
            max_heap_push(&max_heap, val);
            min_size--;
            max_size++;
        }

        if (i >= k - 1) {
            clean_heap(&max_heap, 1);
            clean_heap(&min_heap, 0);
            
            if (k % 2 == 1) {
                result[i - k + 1] = (double)max_heap_top(&max_heap);
            } else {
                double v1 = (double)max_heap_top(&max_heap);
                double v2 = (double)min_heap_top(&min_heap);
                result[i - k + 1] = (v1 + v2) / 2.0;
            }
        }
    }
    return result;
}