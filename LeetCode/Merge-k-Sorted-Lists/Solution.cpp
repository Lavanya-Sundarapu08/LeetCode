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
13    ListNode* mergeKLists(vector<ListNode*>& lists) {
14        priority_queue<pair<int, ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
15
16        for(int i = 0;i<lists.size(); i++){
17            if(lists[i]){
18                pq.push({lists[i] -> val, lists[i]});
19            }
20        }
21
22        ListNode* dummyNode = new ListNode(-1);
23        ListNode* temp = dummyNode;
24
25        while(!pq.empty()){
26            auto it = pq.top();
27            pq.pop();
28            if(it.second->next){
29                pq.push({it.second->next->val, it.second->next});
30            }
31            temp->next = it.second;
32            temp = temp->next;
33        }
34        return dummyNode->next;
35    }
36};