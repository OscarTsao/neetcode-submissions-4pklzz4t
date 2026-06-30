struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int k) : val(k), next(nullptr) {};
};
class MyCircularQueue {
private:
    int capacity;
    int size;
    ListNode* front;
    ListNode* rear;
    
public:
    MyCircularQueue(int k) : capacity(k), size(0), front(nullptr), rear(nullptr) {
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        ListNode* cur = new ListNode(value);
        if (isEmpty()) {
            front = rear = cur;
            rear->next = front;
        }
        else {
            cur->next = rear->next;
            rear->next = cur;
            rear = cur;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        ListNode* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            rear->next = front;
        }
        
        delete temp;
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) return -1;
        else return front->val;
    }
    
    int Rear() {
        if (size == 0) return -1;
        else return rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
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