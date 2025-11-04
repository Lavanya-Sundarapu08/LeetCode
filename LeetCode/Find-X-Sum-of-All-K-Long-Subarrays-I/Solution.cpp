class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
         int n = nums.size();
    vector<int> answer;

    for (int i = 0; i + k <= n; ++i) {
        vector<int> sub(nums.begin() + i, nums.begin() + i + k);
        unordered_map<int, int> freq;

        // 1. Count frequencies
        for (int num : sub) freq[num]++;

        // 2. Make a vector of (number, frequency)
        vector<pair<int,int>> freqList(freq.begin(), freq.end());

        // 3. Sort: higher frequency first, then higher number first
        sort(freqList.begin(), freqList.end(), [](auto &a, auto &b) {
            if (a.second != b.second) return a.second > b.second;  // higher freq first
            return a.first > b.first;  // if tie, larger number first
        });

        // 4. Determine which numbers to keep (top x)
        vector<int> keep;
        for (int j = 0; j < freqList.size() && j < x; ++j)
            keep.push_back(freqList[j].first);

        // 5. Compute sum of subarray including only those numbers
        int subSum = 0;
        for (int num : sub)
            if (find(keep.begin(), keep.end(), num) != keep.end())
                subSum += num;

        answer.push_back(subSum);
    }

    return answer;
    }
};