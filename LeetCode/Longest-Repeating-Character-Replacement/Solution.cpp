1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4
5        vector<int> freq(26,0);
6
7        int left= 0,right = 0;
8
9        int maxCount  = 0;
10
11        int maxLength= 0;
12
13        while(right < s.size()){
14            freq[s[right]- 'A']++;
15
16            maxCount = max(maxCount, freq[s[right]- 'A']);
17
18            while((right - left +1) - maxCount >k){
19                freq[s[left]- 'A']--;
20                left++;
21            }
22
23            maxLength= max(maxLength,right - left+1);
24            right++;
25        }
26        return maxLength;
27    }
28};