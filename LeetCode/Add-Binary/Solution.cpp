1class Solution {
2public:
3    string addBinary(string a, string b) {
4         string r;
5    int i = a.size(), j = b.size(), c = 0;
6
7    while (i || j || c) {
8        if (i) c += a[--i] - '0';
9        if (j) c += b[--j] - '0';
10        r += char(c % 2 + '0');
11        c /= 2;
12    }
13
14    reverse(r.begin(), r.end());
15    return r;
16    }
17};