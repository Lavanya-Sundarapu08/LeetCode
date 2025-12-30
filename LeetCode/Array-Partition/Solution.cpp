1class Solution {
2public:
3    int arrayPairSum(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int sum =0;
6        for(int i =0;i<nums.size();i++){
7            if(i%2==0){
8                sum+=nums[i];
9            }
10        }
11        return sum;
12    }
13};