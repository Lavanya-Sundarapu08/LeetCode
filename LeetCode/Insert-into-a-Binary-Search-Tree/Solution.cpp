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
14    TreeNode* insertIntoBST(TreeNode* root, int val) {
15        if(root == NULL ) return new TreeNode(val);
16
17        TreeNode* cur = root;
18        while(true){
19            if(cur->val <= val){
20                if(cur->right != NULL )  cur= cur->right;
21                else{
22                    cur->right = new TreeNode(val);
23                    break;
24                }
25            }else{
26                if(cur->left != NULL )  cur= cur->left;
27                else{
28                    cur->left = new TreeNode(val);
29                    break;
30                }
31            }
32        }
33        return root;
34    }
35};