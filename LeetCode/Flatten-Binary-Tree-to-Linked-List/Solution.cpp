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
14    void flatten(TreeNode* root) {
15        TreeNode* current = root;
16
17        while (current != nullptr) {
18
19            if (current->left != nullptr) {
20                TreeNode* rightmost =current->left;
21
22                // The rightmost node of the left subtree
23                // must precede the original right subtree.
24                while (rightmost->right != nullptr) {
25                    rightmost = rightmost->right;
26                }
27
28                // The original right subtree is preserved
29                // after the complete left subtree.
30                rightmost->right =current->right;
31
32                // The left subtree is moved to the right
33                // because preorder visits it next.
34                current->right =current->left;
35
36                current->left = nullptr;
37            }
38
39            current = current->right;
40        }
41
42    }
43};