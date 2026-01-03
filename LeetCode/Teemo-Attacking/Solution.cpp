1class Solution {
2public:
3    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
4        int cnt=0;
5        for (int i = 0; i < timeSeries.size(); i++) {
6            if (i == timeSeries.size() - 1) {
7                cnt += duration; 
8            } else {
9                int gap = timeSeries[i + 1] - timeSeries[i];
10                cnt += min(duration, gap);
11            }
12        }
13        return cnt;
14        
15    }
16};