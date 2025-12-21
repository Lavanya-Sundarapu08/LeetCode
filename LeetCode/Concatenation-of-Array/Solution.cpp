1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        vector<int> ans;
5        int n= nums.size();
6
7        for(int i =0;i<n;i++){
8            ans.push_back(nums[i]);
9        }
10        for(int i =0;i<n;i++){
11            ans.push_back(nums[i]);
12        }
13        return ans;
14    }
15};