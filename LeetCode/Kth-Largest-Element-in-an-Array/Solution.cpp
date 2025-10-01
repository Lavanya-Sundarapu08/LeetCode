#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n=nums.size();
        int f=k-1;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(f>0){
            pq.pop();
            f--;
        }
        return pq.top();
    }
    
};

// int main()
// { 
//     int k,n;
//     cin>>n;
//     cin>>k;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     Solution obj;
//     cout<<obj.findKthLargest(nums,k)<<endl;
//     return 0;
// }