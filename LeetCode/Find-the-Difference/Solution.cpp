1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        char result = 0;
5
6        for (char c : s) {
7            result ^= c;
8        }
9        for (char c : t) {
10            result ^= c;
11        }
12
13        return result;
14    }
15};