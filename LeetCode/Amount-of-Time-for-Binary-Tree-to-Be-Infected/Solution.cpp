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
13private:
14
15     struct Info {
16        int height;
17        int distanceFromStart;
18    };
19
20    Info dfs(TreeNode* node, int start, int& maxTime) {
21        if (node == nullptr) {
22            return {-1, -1};
23        }
24
25        Info left = dfs(node->left, start, maxTime);
26        Info right = dfs(node->right, start, maxTime);
27
28        int height = 1 + max(left.height, right.height);
29
30        if (node->val == start) {
31            maxTime = max(maxTime, height);
32            return {height, 0};
33        }
34
35        if (left.distanceFromStart != -1) {
36            int distanceFromStart =
37                left.distanceFromStart + 1;
38
39            maxTime = max(
40                maxTime,
41                distanceFromStart + 1 + right.height
42            );
43
44            return {height, distanceFromStart};
45        }
46
47        if (right.distanceFromStart != -1) {
48            int distanceFromStart =
49                right.distanceFromStart + 1;
50
51            maxTime = max(
52                maxTime,
53                distanceFromStart + 1 + left.height
54            );
55
56            return {height, distanceFromStart};
57        }
58
59        return {height, -1};
60    }
61public:
62
63    int amountOfTime(TreeNode* root, int start) {
64        int maxTime = 0;
65
66        dfs(root, start, maxTime);
67
68        return maxTime;
69    }
70};