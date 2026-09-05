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
14    int maxPathSum(TreeNode* root) {
15        int maxi = INT_MIN;
16        maxPathDown(root, maxi);
17        return maxi;
18    }
19
20    int maxPathDown(TreeNode* node, int& maxi){
21        if(node == NULL) return 0;
22        int left = max(0, maxPathDown(node->left, maxi));
23        int right = max(0, maxPathDown(node->right, maxi));
24        maxi = max(maxi,node->val+left+right);
25        return max(left,right)+node->val;
26    }
27};