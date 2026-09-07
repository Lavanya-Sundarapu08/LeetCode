1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    vector<vector<int>> verticalTraversal(TreeNode* root) {
15        map<int, map<int, multiset<int>>> nodes;
16        queue<pair<TreeNode* , pair<int,int>>> todo;
17
18        todo.push({root,{0,0}});
19
20        while(!todo.empty()){
21            auto p = todo.front();
22            todo.pop();
23            TreeNode* node=  p.first;
24            int x = p.second.first, y = p.second.second;
25
26            nodes[x][y].insert(node->val);
27            if(node->left){
28                todo.push({node->left,{x - 1, y+1}});
29            }
30            if(node->right){
31                todo.push({node->right,{x+1,y+1}});
32            }
33        }
34        vector<vector<int>> ans;
35        for(auto p : nodes){
36            vector<int> col;
37            for(auto q: p.second){
38                col.insert(col.end(), q.second.begin(),q.second.end());
39            }
40            ans.push_back(col);
41        }
42        return ans;
43    }
44};