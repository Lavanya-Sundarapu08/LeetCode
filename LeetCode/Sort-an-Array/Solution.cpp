1class Solution {
2public:
3
4    void merge(vector<int>& nums, int low, int mid, int high) {
5        vector<int> temp;
6
7        int left = low;
8        int right = mid + 1;
9
10        while (left <= mid && right <= high) {
11            if (nums[left] <= nums[right]) {
12                temp.push_back(nums[left++]);
13            } else {
14                temp.push_back(nums[right++]);
15            }
16        }
17
18        while (left <= mid)
19            temp.push_back(nums[left++]);
20
21        while (right <= high)
22            temp.push_back(nums[right++]);
23
24        for (int i = low; i <= high; i++) {
25            nums[i] = temp[i - low];
26        }
27    }
28    void mergeSort(vector<int>& nums, int low, int high) {
29        if (low >= high)
30            return;
31
32        int mid = low + (high - low) / 2;
33
34        mergeSort(nums, low, mid);
35        mergeSort(nums, mid + 1, high);
36
37        merge(nums, low, mid, high);
38    }
39    vector<int> sortArray(vector<int>& nums) {
40        mergeSort(nums, 0, nums.size() - 1);
41        return nums;
42    }
43};