1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* removeElements(ListNode* head, int val) {
14        ListNode* dummy = new ListNode(0);
15        dummy->next = head;
16
17        ListNode* curr = dummy;
18
19        while (curr->next != nullptr) {
20
21            if (curr->next->val == val) {
22                curr->next = curr->next->next;
23            }
24            else {
25                curr = curr->next;
26            }
27        }
28
29        return dummy->next;
30    }
31};