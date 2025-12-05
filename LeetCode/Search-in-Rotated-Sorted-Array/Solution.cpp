1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int low = 0 , high = n-1;
6        while(low <= high){
7            int mid = (low+high) /2;
8            if(nums[mid] == target) return mid;
9            //left sorted array
10            else if(nums[low]<= nums[mid]){
11                if(nums[low]<= target && target <= nums[mid]){
12                    high = mid-1;
13                }else{
14                    low = mid+1;
15                }
16            }//right sorted array
17            else{
18                if(nums[high]>= target && target >=nums[mid] ){
19                    low = mid+1;
20                }else{
21                    high = mid-1;
22                }
23            }
24        }
25        return -1;
26    }
27};