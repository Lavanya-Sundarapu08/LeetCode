1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        vector<int> res;
5        int n = nums.size();
6        sort(nums.begin(),nums.end());
7        unordered_set<int> st(nums.begin(),nums.end());
8        vector<int> missing;
9        for(int i = nums[0]+1; i < nums.back();++i){
10            if(!st.count(i)){
11                missing.push_back(i);
12            }
13        }return missing;
14        
15
16    }
17};