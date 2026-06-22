class MyCircularQueue {
private:
    vector<int> buffer;
    int head;       // The read pointer
    int count;      // How many elements are currently in the queue
    int capacity;   // The max size (k)

public:
    MyCircularQueue(int k) {
        buffer.resize(k);
        capacity = k;
        head = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        // Calculate the next available write position
        int tail = (head + count) % capacity;
        buffer[tail] = value;
        count++;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        // Just move the head pointer! The old data will be overwritten later.
        head = (head + 1) % capacity;
        count--;
        
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return buffer[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // Calculate where the last inserted element is
        int tail = (head + count - 1) % capacity;
        return buffer[tail];
    }
    
    bool isEmpty() {
        return count == 0; 
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */