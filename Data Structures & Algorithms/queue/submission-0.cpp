struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {};    
};

class Deque {
private:
    ListNode* head;
    ListNode* tail;
public:
    Deque() {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    void append(int value) {
        ListNode* newNode = new ListNode(value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;
    }

    void appendleft(int value) {
        ListNode* newNode = new ListNode(value);
        head->next->prev = newNode;
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
    }

    int pop() {
        if (isEmpty()) return -1;
        ListNode* tmp = tail->prev;
        int value = tmp->val;
        tail->prev = tail->prev->prev;
        tmp->prev->next = tail;
        delete tmp;
        return value;
    }

    int popleft() {
        if (isEmpty()) return -1;
        ListNode* tmp = head->next;
        int value = tmp->val;
        head->next = tmp->next;
        tmp->next->prev = head;
        delete tmp;
        return value;
    }
};
