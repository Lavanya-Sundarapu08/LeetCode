1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4        vector<vector<int>> ans;
5        int n = nums.size();
6        sort(nums.begin(),nums.end());
7        for(int i = 0;i<n;i++){
8            if(i>0 && nums[i] == nums[i-1]) continue;
9            for(int j = (i+1) ; j <n; j++){
10                if(j>i+1 && nums[j] == nums[j-1])  continue;
11                int k = j+1;
12                int l = n-1;
13                while(k<l){
14                    long long sum = nums[i];
15                    sum += nums[j];
16                    sum += nums[k];
17                    sum += nums[l];
18                    if(sum == target){
19                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
20                    ans.push_back(temp);
21                    k++;
22                    l--;
23                    while(k<l && nums[k] == nums[k-1]) k++;
24                    while(k<l && nums[l] == nums[l+1]) l--;
25                    }
26                    else if(sum>target) l--;
27                    else k++;
28                }
29            }
30        }
31        return ans;
32    }
33};