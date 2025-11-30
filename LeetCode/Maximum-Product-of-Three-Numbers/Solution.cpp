1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        
7        int option1 = nums[n-1] * nums[n-2] * nums[n-3];     // 3 largest
8        int option2 = nums[0] * nums[1] * nums[n-1];         // 2 smallest + largest
9        
10        return max(option1, option2);
11    }
12};