class MyCircularDeque {
private:
vector<int> arr;
int front;
int last;
int count;
int max;
public:
    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0;
        last = 0;
        count = 0;
        max = k;
    }
    
    bool insertFront(int value) {
        if (count == max) return false;
        front = (front - 1 + max) % max;;
        arr[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (count == max) return false;
        arr[last] = value;
        last = (last + 1) % max;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (count == 0) return false;
        front = (front + 1) % max;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (count == 0) return false;
        last = (last - 1 + max) % max;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return  arr[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return  arr[(last - 1 + max) % max];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == max;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */