1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if (s.length() != goal.length()) {
5            return false;
6        }
7        return (s + s).contains(goal);
8    }
9};