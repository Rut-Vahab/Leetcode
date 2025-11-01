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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        if (!head) {
            return nullptr;
        }
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        if (n == count) {
            ListNode* headNew = head->next;
            delete head;
            return headNew;
        }
        temp = head;
        for (int i = 0; i < count - n-1; i++) {
            temp = temp->next;
        }
        ListNode* nodeToDelet = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelet;
        return head;
    }
};