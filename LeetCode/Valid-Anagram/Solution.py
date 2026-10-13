1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if (s.length() != t.length())
5            return false;
6
7        int freq[26] = {0};
8
9        for (char c : s)
10            freq[c - 'a']++;
11
12        for (char c : t) {
13            freq[c - 'a']--;
14            if (freq[c - 'a'] < 0)
15                return false;
16        }
17
18        return true;
19    }
20};