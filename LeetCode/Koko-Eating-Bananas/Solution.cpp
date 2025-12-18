1class Solution {
2public:
3
4    long long calculateTotalHours(vector<int>& piles, int speed) {
5        long long totalH = 0;
6        for (int bananas : piles) {
7            totalH += (bananas +speed - 1) / speed;
8        }
9        return totalH;
10    }
11
12    // Function to find minimum eating speed
13    int minEatingSpeed(vector<int>& piles, int h) {
14        // Find maximum element
15        int maxPile = *max_element(piles.begin(), piles.end());
16
17        // Initialize low and high pointers
18        int low = 1, high = maxPile;
19        int ans = maxPile;
20
21        // Binary search on answer space
22        while (low <= high) {
23            int mid = (high+low)/ 2;
24            long long totalH = calculateTotalHours(piles, mid);
25
26            // If possible, try smaller speed
27            if (totalH <= h) {
28                ans = mid;
29                high = mid - 1;
30            }
31            // Otherwise, try larger speed
32            else {
33                low = mid + 1;
34            }
35        }
36        return ans;
37    }
38};