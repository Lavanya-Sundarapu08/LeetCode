1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4        int n = nums.size();
5        if( n== 1) return nums[0];
6        if (nums[0] != nums[1]) return nums[0];
7        if(nums[n - 1] != nums[n-2]) return nums[n-1];
8        int low = 1,high = n-2;
9        while(low<= high){
10            int mid= (low+high)/2;
11            if(nums[mid ]!= nums[mid- 1] && nums[mid]!= nums[mid +1]){
12                return nums[mid];
13            }
14            if((mid%2== 0 && nums[mid] ==  nums[mid+1])|| (mid%2 == 1 && nums[mid] ==  nums[mid-1])){
15                low = mid+1;
16            }else{
17                high = mid-1;
18            }
19        }
20    return -1;
21    }
22};