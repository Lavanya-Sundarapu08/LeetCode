class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res =0;
        for(int i=0;i<nums.size();i++){
            
            if(target == nums[i]){
                res=i;
                break;
            }
            else{
                res = -1;
            }
        }
        return res;
    }
};