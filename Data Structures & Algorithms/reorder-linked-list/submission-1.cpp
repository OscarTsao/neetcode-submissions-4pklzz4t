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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) { 
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        
        ListNode* prev = nullptr;
        ListNode* cur = head2;
        while (cur) {
            ListNode*next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head2 = prev;

        ListNode* head1 = head;
        while (head1 && head2) {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;
            head1->next = head2;
            head2->next = next1;
            head1 = next1;
            head2 = next2;
        }
    }
};
