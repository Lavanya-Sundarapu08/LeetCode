1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        return nums[ nums.size()/2];
6    }
7};