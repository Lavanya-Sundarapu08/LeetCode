1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        int dup =-1,missing = -1;
5        
6        for(int i=0;i<nums.size();i++){
7            int idx = abs(nums[i])-1;
8            
9            if(nums[idx] < 0){
10                dup = abs(nums[i]);
11            }else{
12                nums[idx] = -nums[idx];
13            }
14        }
15
16
17        for(int i =0;i<nums.size();i++){
18            if(nums[i] > 0){
19                missing = i+1;
20                break;
21            }
22        }
23        return {dup,missing};
24
25    }
26};