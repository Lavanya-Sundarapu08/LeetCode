1class Solution {
2public:
3
4    int getMaxDigit(int num) {
5
6        int maxi = 0;
7
8        while(num > 0) {
9            maxi = max(maxi, num % 10);
10            num /= 10;
11        }
12
13        return maxi;
14    }
15    int maxSum(vector<int>& nums) {
16        
17        unordered_map<int, int> mp; 
18        int ans = -1;
19
20        for(int num : nums) {
21            int digit = getMaxDigit(num);
22
23            if(mp.count(digit)){
24                ans = max(ans, num + mp[digit]);
25                mp[digit] = max(mp[digit], num);
26
27            }else{
28                mp[digit] = num;
29            }
30        }
31        return ans;
32    }
33};