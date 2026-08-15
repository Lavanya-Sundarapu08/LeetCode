1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int rXOR = 0;
5        int res= 0;
6        bool ans = false;
7
8        for(int reqX : nums){
9            rXOR ^= reqX;
10            if(rXOR != 0){
11                ans = true;
12            }
13        }
14
15        if(rXOR != 0){
16            res = nums.size();
17        }else if(ans){
18            res= nums.size()-1;
19        }else{
20            res = 0;
21        }
22        return res;
23    }
24};