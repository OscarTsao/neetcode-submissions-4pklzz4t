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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0, list1);
        ListNode* cur = head;
        while (cur->next != nullptr && list2 != nullptr) {
            if (cur->next->val > list2->val) {
                ListNode* tmp = list2->next;
                list2->next = cur->next;
                cur->next = list2;
                list2 = tmp;
            }
            cur = cur->next;
        }
        if (list2 != nullptr) {
            cur->next = list2;
        }
        return head->next;
    }
};
