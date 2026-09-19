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
12    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
13        if (!root) return {};
14
15        // Step 1: Build parent mapping for each node using BFS
16        unordered_map<TreeNode*, TreeNode*> parentMap;
17        mapParentNodes(root, parentMap);
18
19        // Step 2: Perform BFS from target to find nodes at distance K
20        return bfsFromTarget(target, parentMap, k);
21    }
22     void mapParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
23        queue<TreeNode*> q;
24        q.push(root);
25
26        // Level-order traversal to map parent of each node
27        while (!q.empty()) {
28            TreeNode* node = q.front();
29            q.pop();
30
31            // If left child exists, record its parent and add it to queue
32            if (node->left) {
33                parentMap[node->left] = node;
34                q.push(node->left);
35            }
36
37            // If right child exists, record its parent and add it to queue
38            if (node->right) {
39                parentMap[node->right] = node;
40                q.push(node->right);
41            }
42        }
43    }
44
45     vector<int> bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
46        queue<TreeNode*> q;
47        unordered_set<TreeNode*> visited; 
48
49        // Start BFS from the target node
50        q.push(target);
51        visited.insert(target);
52
53        int currentLevel = 0;
54
55        // Perform level-order BFS until we reach level K
56        while (!q.empty()) {
57            int size = q.size();
58
59            // If we've reached level k, break out and collect the result
60            if (currentLevel++ == k) break;
61
62            // Explore all nodes at current level
63            for (int i = 0; i < size; ++i) {
64                TreeNode* node = q.front();
65                q.pop();
66
67                // Explore left child if not already visited
68                if (node->left && visited.find(node->left) == visited.end()) {
69                    visited.insert(node->left);
70                    q.push(node->left);
71                }
72
73                // Explore right child if not already visited
74                if (node->right && visited.find(node->right) == visited.end()) {
75                    visited.insert(node->right);
76                    q.push(node->right);
77                }
78
79                // Explore parent from parentMap if not already visited
80                // Only proceed if the current node has a parent in the map
81                // This avoids inserting a null parent for the root node (which has no parent)
82                // and prevents accidental segfaults from accessing nullptr
83                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
84                    visited.insert(parentMap[node]);
85                    q.push(parentMap[node]);
86                }
87            }
88        }
89
90        // All nodes in queue are now at distance K from the target
91        vector<int> result;
92        while (!q.empty()) {
93            result.push_back(q.front()->val);
94            q.pop();
95        }
96
97        return result;
98    }
99};