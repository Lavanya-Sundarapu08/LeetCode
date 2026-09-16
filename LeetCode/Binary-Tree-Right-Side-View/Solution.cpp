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
14 void leftDFS(TreeNode* node, int level, vector<int>& res) {
15        // Base case: null node
16        if (!node) return;
17
18        // If this is the first node at the current level
19        if (res.size() == level)
20            res.push_back(node->val);
21
22        // Explore left subtree first
23        leftDFS(node->left, level + 1, res);
24
25        // Then explore right subtree
26        leftDFS(node->right, level + 1, res);
27    }
28
29    // Recursive function to get right view
30    void rightDFS(TreeNode* node, int level, vector<int>& res) {
31        if (!node) return;
32
33        if (res.size() == level)
34            res.push_back(node->val);
35
36        // Explore right subtree first
37        rightDFS(node->right, level + 1, res);
38
39        // Then explore left subtree
40        rightDFS(node->left, level + 1, res);
41    }
42
43    vector<int> leftView(TreeNode* root) {
44        vector<int> res;
45        leftDFS(root, 0, res);
46        return res;
47    }
48    vector<int> rightSideView(TreeNode* root) {
49        vector<int> res;
50        rightDFS(root, 0, res);
51        return res;
52    }
53};