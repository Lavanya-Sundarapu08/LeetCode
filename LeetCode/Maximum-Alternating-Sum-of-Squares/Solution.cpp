1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        int n = nums.size();
5        for(int i = 0 ; i< n; i++){
6            nums[i]= nums[i] * nums[i];
7        }
8
9        sort(nums.begin(), nums.end());
10
11        long long ans = 0;
12        int mid = (n/2) ;
13
14        for(int i = 0 ;i < mid ; i++){
15            ans-= nums[i];
16        }
17        for(int i = mid ;i < n ; i++){
18            ans += nums[i];
19        }
20        return ans;
21    }
22};