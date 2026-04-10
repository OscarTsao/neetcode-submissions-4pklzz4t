class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}

};


class LinkedList {
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr){
            if (i == index)
                return curr->val;
            else{
                i++;
                curr = curr->next;
            }
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* newHead = new ListNode(val, head);
        newHead->next = head->next;
        head->next = newHead;
        if (newHead->next == nullptr) tail = newHead;
    }
    
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
        ListNode* curr = head;
        int i = 0;

        while (i < index && curr != nullptr){
            curr = curr->next;
            i++;
        }
        if (curr != nullptr && curr->next != nullptr){
            if (curr->next == tail) tail = curr;
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        ListNode* curr = head->next;
        vector<int> res;
        while(curr){
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
