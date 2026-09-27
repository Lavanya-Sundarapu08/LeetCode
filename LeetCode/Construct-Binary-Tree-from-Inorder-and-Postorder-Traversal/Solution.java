1/**
2 * Definition for a binary tree node.
3 * public class TreeNode {
4 *     int val;
5 *     TreeNode left;
6 *     TreeNode right;
7 *     TreeNode() {}
8 *     TreeNode(int val) { this.val = val; }
9 *     TreeNode(int val, TreeNode left, TreeNode right) {
10 *         this.val = val;
11 *         this.left = left;
12 *         this.right = right;
13 *     }
14 * }
15 */
16class Solution {
17     int postIndex;
18    int[] inorder;
19    int[] postorder;
20    public TreeNode buildTree(int[] inorder, int[] postorder) {
21         this.inorder = inorder;
22        this.postorder = postorder;
23        postIndex = postorder.length - 1;
24
25        return build(0, inorder.length - 1);
26    }
27    private TreeNode build(int left, int right) {
28        if (left > right) {
29            return null;
30        }
31
32        // Last element in postorder is the root
33        int rootValue = postorder[postIndex--];
34        TreeNode root = new TreeNode(rootValue);
35
36        // Find root in inorder
37        int index = left;
38        while (inorder[index] != rootValue) {
39            index++;
40        }
41
42        // IMPORTANT: build right first
43        root.right = build(index + 1, right);
44        root.left = build(left, index - 1);
45
46        return root;
47    }
48}