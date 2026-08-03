1class Solution {
2public:
3    void heapify(vector<int>& nums, int n, int i) {
4        int largest = i;
5        int left = 2 * i + 1;
6        int right = 2 * i + 2;
7
8        if (left < n && nums[left] > nums[largest])
9            largest = left;
10
11        if (right < n && nums[right] > nums[largest])
12            largest = right;
13
14        if (largest != i) {
15            swap(nums[i], nums[largest]);
16            heapify(nums, n, largest);
17        }
18    }
19    vector<int> sortArray(vector<int>& nums) {
20        int n = nums.size();
21
22        for (int i = n / 2 - 1; i >= 0; i--)
23            heapify(nums, n, i);
24
25        for (int i = n - 1; i > 0; i--) {
26            swap(nums[0], nums[i]);
27            heapify(nums, i, 0);
28        }
29
30        return nums;
31    }
32};