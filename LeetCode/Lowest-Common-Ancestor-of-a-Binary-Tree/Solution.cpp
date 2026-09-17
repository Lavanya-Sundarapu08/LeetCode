1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if (root == NULL || root == p || root == q) {
14            return root;
15        }
16        
17        // Search in left and right subtrees
18        TreeNode* left = lowestCommonAncestor(root->left, p, q);
19        TreeNode* right = lowestCommonAncestor(root->right, p, q);
20        
21        // Result
22        if (left == NULL) {
23            return right;
24        } else if (right == NULL) {
25            return left;
26        } else { // Both left and right are not null, we found our result
27            return root;
28        }
29    }
30};