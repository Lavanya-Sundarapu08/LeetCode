1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        vector<int> ans;
5        int n = nums.size();
6
7         vector<bool> present(n+1,false);
8
9        for(auto i:nums){
10            present[i] = true;
11        }
12
13        for(int i =1;i<=n;i++){
14            if(!present[i]){
15                ans.push_back(i);
16            }
17        }
18        return ans;
19    }
20};