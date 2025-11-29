1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        
5        int sum = accumulate(nums.begin(), nums.end(), 0);//9
6        int num2= sum%k;//4
7        return num2;
8    }
9};