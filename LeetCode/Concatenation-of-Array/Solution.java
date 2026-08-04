1class Solution {
2    public int[] getConcatenation(int[] nums) {
3        int n = nums.length;
4
5        int[] ans= new int[2*n];
6
7        for(int i=0;i<n;i++){
8            ans[i] = nums[i];
9            ans[i+n]= nums[i];
10        }
11        return ans;
12
13    }
14}