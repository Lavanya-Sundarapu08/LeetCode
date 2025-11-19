class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool found = true;
        while(found){
            found = false;
            for(auto num : nums){
                if(num == original){
                    original*= 2;
                    found = true;
                    break;
                }
            }
        }
        return original;
    }
};