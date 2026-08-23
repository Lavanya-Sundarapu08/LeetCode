1class Solution {
2public:
3    bool sumGame(string num) {
4        int n = num.size();
5        int sum = 0, q = 0;
6
7        for (int i = 0; i < n; i++) {
8            if (num[i] == '?') {
9                q += (i < n / 2 ? 1 : -1);
10            } else {
11                sum += (i < n / 2 ? 1 : -1) * (num[i] - '0');
12            }
13        }
14        if ((abs(q) & 1) || abs(sum + q / 2 * 9) != 0)
15            return true;
16
17        return false;
18    }
19};