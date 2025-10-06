class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int N = nums.size();
     int  K=0;
    for (int i = 0; i < N - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i
       
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == K) {
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                // Skip duplicates for left
                while (left < right && nums[left] == nums[left - 1]) left++;
                // Skip duplicates for right
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (sum < K) {
                left++;
            } else {
                right--;
            }
        }
    }

    return res;
    }
};