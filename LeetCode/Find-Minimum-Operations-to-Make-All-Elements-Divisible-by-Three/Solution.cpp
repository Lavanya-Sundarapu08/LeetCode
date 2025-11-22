class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt  = 0;
        for(int i = 0 ;i< n ; i++){
            if(nums[i]%3==0);
            else{
                nums[i] = nums[i]+abs(nums[i]-3);
                cnt++;
            }
        }return cnt;
    }
};