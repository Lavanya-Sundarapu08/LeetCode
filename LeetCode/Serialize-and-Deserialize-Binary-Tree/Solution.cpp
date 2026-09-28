1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13     string serialize(TreeNode* root) {
14        if (root == nullptr) {
15            return "#";
16        }
17
18        string data;
19        queue<TreeNode*> q;
20        q.push(root);
21
22        while (!q.empty()) {
23            TreeNode* node = q.front();
24            q.pop();
25
26            if (node == nullptr) {
27                data += "#,";
28                continue;
29            }
30
31            data += to_string(node->val) + ",";
32
33            q.push(node->left);
34            q.push(node->right);
35        }
36
37        return data;
38    }
39
40    TreeNode* deserialize(string data) {
41        if (data == "#") {
42            return nullptr;
43        }
44
45        vector<string> tokens;
46        string token;
47        stringstream ss(data);
48
49        while (getline(ss, token, ',')) {
50            tokens.push_back(token);
51        }
52
53        TreeNode* root = new TreeNode(stoi(tokens[0]));
54
55        queue<TreeNode*> q;
56        q.push(root);
57
58        int index = 1;
59
60        while (!q.empty() && index < tokens.size()) {
61
62            TreeNode* node = q.front();
63            q.pop();
64
65            // LEFT
66            if (tokens[index] != "#") {
67                node->left = new TreeNode(stoi(tokens[index]));
68                q.push(node->left);
69            }
70            index++;
71
72            // RIGHT
73            if (index < tokens.size() && tokens[index] != "#") {
74                node->right = new TreeNode(stoi(tokens[index]));
75                q.push(node->right);
76            }
77            index++;
78        }
79
80        return root;
81    }
82};
83
84// Your Codec object will be instantiated and called as such:
85// Codec ser, deser;
86// TreeNode* ans = deser.deserialize(ser.serialize(root));