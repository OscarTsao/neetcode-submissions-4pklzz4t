/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* second_rev = prev;
        while (second_rev != nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second_rev->next;
            
            first->next = second_rev;
            second_rev->next = tmp1;
            
            first = tmp1;
            second_rev = tmp2;
        }
    }
};