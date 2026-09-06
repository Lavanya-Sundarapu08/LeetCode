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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        vector<vector<int>> result;
16
17        if(!root) return result;
18
19        //BFS level by level
20        queue<TreeNode*> q;
21        q.push(root);
22
23        bool leftToRight = true;
24
25        while(!q.empty()){
26
27            //get no of nodes in the present level 
28            int size = q.size();
29
30            //stores correct zig zag manner
31            vector<int> level(size);
32
33            for(int i = 0;i<size;i++){
34                TreeNode* node = q.front();
35                q.pop();
36
37                int index = leftToRight ? i : size - 1 - i;
38                level[index] = node->val;
39
40                if(node->left) q.push(node->left);
41                if(node->right) q.push(node->right);
42            }
43
44
45            leftToRight = !leftToRight;
46
47            result.push_back(level);
48        }
49        return result;
50    }
51};