1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int left=0;
5        int right= numbers.size()-1;
6
7        while( left < right){
8            int sum = numbers[right] + numbers[left];
9
10            if(sum == target) {
11                return {left+1, right+1};
12            }
13            else if(sum < target){
14                left++;
15            }else{
16                right--;
17            }
18        }
19        return {};
20    }
21};