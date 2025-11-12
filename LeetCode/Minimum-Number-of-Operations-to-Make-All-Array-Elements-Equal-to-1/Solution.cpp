class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int initial_gcd = nums[0];
        for(int i=0 ; i< n; i++){
            initial_gcd = gcd(initial_gcd,nums[i]);


        }
        if(initial_gcd != 1){
            return -1;
        }

        int count_ones = 0;
        for (int x : nums)
            if (x == 1)
                count_ones++;

        if (count_ones > 0)
            return n - count_ones;

        int minisub = INT_MAX;
        for(int i = 0;i<n;i++){
            int curr_gcd = nums[i];
            if(curr_gcd ==1){
                minisub = 1;
                break;
            }

            for(int j = 1+i ;j<n;j++){
                curr_gcd = gcd(curr_gcd,nums[j]);
                if(curr_gcd == 1){
                    minisub= min(minisub,j-i+1);
                    break;
                }
            }
        }

        int ops = (minisub - 1)+(n - 1);
        return ops;
    }
};