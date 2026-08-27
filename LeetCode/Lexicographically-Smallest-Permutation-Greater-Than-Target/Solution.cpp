1class Solution {
2public:
3    string lexGreaterPermutation(string s, string target) {
4        sort(s.begin(), s.end());
5
6        int n = s.size();
7
8        for (int i = n - 1; i >= 0; i--) {
9
10            // Keep prefix same as target
11            string prefix = target.substr(0, i);
12
13            // Check if prefix can be formed from s
14            string remaining = s;
15
16            bool possible = true;
17            for (char c : prefix) {
18                int pos = remaining.find(c);
19
20                if (pos == string::npos) {
21                    possible = false;
22                    break;
23                }
24
25                remaining.erase(pos, 1);
26            }
27         if (!possible)
28                continue;
29
30            // Find smallest character > target[i]
31            for (int j = 0; j < remaining.size(); j++) {
32
33                if (remaining[j] > target[i]) {
34
35                    string ans = prefix;
36                    ans += remaining[j];
37
38                    remaining.erase(j, 1);
39
40                    sort(remaining.begin(), remaining.end());
41
42                    ans += remaining;
43
44                    return ans;
45                }
46            }
47        }
48
49        return "";
50    }
51};