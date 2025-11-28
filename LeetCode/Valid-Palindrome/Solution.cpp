1class Solution {
2public:
3    bool isPalindrome(string s) {
4        s.erase(remove_if(s.begin(), s.end(),
5                      [](char c){ return !isalnum(c); }),
6            s.end());
7
8    // 2. Convert to lowercase
9    transform(s.begin(), s.end(), s.begin(),
10              [](unsigned char c){ return tolower(c); });
11
12    // 3. Check palindrome using reverse
13    string rev = s;
14    reverse(rev.begin(), rev.end());
15
16    return s == rev;
17    }
18};