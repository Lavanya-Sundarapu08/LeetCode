1class Solution {
2public:
3    int sumOfDivisor(vector<int>& nums,int mid){
4        int sum =0;
5        int n = nums.size();
6        for(int i =0;i<n;i++){
7            sum += ceil((double)nums[i]/(double)mid);
8        }
9        return sum;
10    }
11    int smallestDivisor(vector<int>& nums, int threshold) {
12        int low = 1, high = *max_element(nums.begin(),nums.end());
13        while(low<= high){
14            int mid = (low+high)/2;
15            if( sumOfDivisor(nums,mid) <= threshold){
16                high  = mid-1;
17            }else{
18                low = mid +1;
19            }
20        }
21        return low;
22    }
23};