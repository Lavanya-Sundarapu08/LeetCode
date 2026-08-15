1#include <bits/stdc++.h> 
2using namespace std;
3class Solution {
4public:
5    int findKthLargest(vector<int>& nums, int k) {
6        priority_queue<int> pq;
7        int n=nums.size();
8        int f=k-1;
9
10        for(int i=0;i<nums.size();i++){
11            pq.push(nums[i]);
12        }
13
14        while(f>0){
15            pq.pop();
16            f--;
17        }
18        return pq.top();
19    }
20    
21};
22
23// int main()
24// { 
25//     int k,n;
26//     cin>>n;
27//     cin>>k;
28//     vector<int> nums(n);
29//     for(int i=0;i<n;i++){
30//         cin>>nums[i];
31//     }
32//     Solution obj;
33//     cout<<obj.findKthLargest(nums,k)<<endl;
34//     return 0;
35// }