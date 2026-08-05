1class Solution:
2    def reverse(self, x: int) -> int:
3        sign = -1 if x < 0 else 1
4        x *= sign
5        rev = 0
6
7        while x:
8            rev = rev * 10 + x % 10
9            x //= 10
10
11        rev *= sign
12
13        return rev if -2**31 <= rev <= 2**31 - 1 else 0