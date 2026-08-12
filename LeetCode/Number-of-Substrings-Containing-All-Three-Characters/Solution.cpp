1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        vector<int> freq(3,0);
5        int ans = 0;
6
7        int left = 0;
8
9        for(int right = 0;right < s.length() ; right++){
10            freq[s[right]-'a']++;
11
12            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
13                ans += (s.length() - right);
14
15                freq[s[left] - 'a']--;
16                left++;
17            }
18        }
19        return ans;
20    }
21};