1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int n = nums.size();
5    int cnt = 0; // count
6    int el; // Element
7
8    //applying the algorithm:
9    for (int i = 0; i < n; i++) {
10        if (cnt == 0) {
11            cnt = 1;
12            el = nums[i];
13        }
14        else if (el == nums[i]) cnt++;
15        else cnt--;
16    }
17
18    //checking if the stored element
19    // is the majority element:
20    int cnt1 = 0;
21    for (int i = 0; i < n; i++) {
22        if (nums[i] == el) cnt1++;
23    }
24
25    if (cnt1 > (n / 2)) return el;
26    return -1;
27}
28
29};