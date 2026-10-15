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
12class BSTIterator {
13private: stack<TreeNode *> myStack;
14public:
15    BSTIterator(TreeNode* root) {
16        pushAll(root);
17    }
18    
19    int next() {
20        TreeNode *tmpNode = myStack.top();
21        myStack.pop();
22        pushAll(tmpNode->right);
23        return tmpNode->val;
24    }
25    
26    bool hasNext() {
27        return !myStack.empty();
28    }
29private: 
30    void pushAll(TreeNode * node){
31        for(; node != NULL; myStack.push(node),node = node->left );
32    }
33};
34
35/**
36 * Your BSTIterator object will be instantiated and called as such:
37 * BSTIterator* obj = new BSTIterator(root);
38 * int param_1 = obj->next();
39 * bool param_2 = obj->hasNext();
40 */