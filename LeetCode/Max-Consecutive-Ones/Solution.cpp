1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int n= nums.size();
5        int cnt = 0;
6        int ans=0;
7        for(int i =0;i<n;i++){
8            if(nums[i]==1){
9                cnt++;
10                ans=max(ans,cnt);
11            }else{
12                ans = max(ans,cnt);
13                cnt=0;
14            }
15        }
16        return ans;
17    }
18};