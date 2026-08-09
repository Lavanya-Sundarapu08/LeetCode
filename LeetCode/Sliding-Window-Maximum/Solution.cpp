1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int> dq;
5
6        vector<int> result;
7
8        for(int i =0 ; i< nums.size();i++){
9            if(!dq.empty() && dq.front() <= i-k){
10                dq.pop_front();
11            }
12
13            while(!dq.empty() &&  nums[dq.back()] <= nums[i]){
14                dq.pop_back();
15            }
16
17            dq.push_back(i);
18
19            if( i >= k-1){
20                result.push_back(nums[dq.front()]);
21            }
22        }
23        return result;
24    }
25};