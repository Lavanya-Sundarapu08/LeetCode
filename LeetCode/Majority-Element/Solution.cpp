1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int count = 0;
5        int candidate = 0;
6
7        for(int x:nums){
8            if(count==0){
9                candidate=x;
10            }
11
12            if(x == candidate) count++;
13            else count--;
14        }
15        return candidate;
16    }
17};