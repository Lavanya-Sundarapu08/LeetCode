1class Solution {
2public:
3    int thirdMax(vector<int>& nums) {
4         set<int> Nums(nums.begin(), nums.end());
5         
6        vector<int> ans(Nums.begin(), Nums.end());
7         int n = ans.size();
8
9        if (n < 3) {
10            return ans[n - 1];   // return max
11        }
12
13        return ans[n - 3];
14    }
15};