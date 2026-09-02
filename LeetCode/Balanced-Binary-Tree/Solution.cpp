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
14    bool isBalanced(TreeNode* root) {
15        return dfsHeight(root) != -1;
16    }
17
18    int dfsHeight(TreeNode *root){
19        if( root == NULL) return  0;
20
21        int leftHeight = dfsHeight(root -> left);
22        if(leftHeight == -1) return -1;
23
24        int rightHeight = dfsHeight(root -> right);
25        if(rightHeight == -1) return -1;
26
27        if( abs(leftHeight - rightHeight) > 1) return -1;
28        return max(leftHeight,rightHeight)+1;
29    }
30};
31
32