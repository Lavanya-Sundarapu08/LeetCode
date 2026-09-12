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
14    bool isSymmetric(TreeNode* root) {
15        if(!root){
16            return true;
17        }
18
19        return isSymmetricCheck(root->left, root->right);
20    }
21
22    bool isSymmetricCheck(TreeNode* root1, TreeNode* root2){
23        if(root1 == NULL || root2 == NULL){
24            return root1 == root2;
25        }
26
27        return (root1->val == root2->val)
28                &&isSymmetricCheck(root1->left, root2->right)
29                && isSymmetricCheck(root1->right, root2->left);
30    }
31};