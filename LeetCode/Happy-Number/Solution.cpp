1class Solution {
2public:
3
4    int getSquareSum(int n) {
5        int sum = 0;
6        while (n > 0) {
7            int digit = n % 10;
8            sum += digit * digit;
9            n /= 10;
10        }
11        return sum;
12    }
13    
14    bool isHappy(int n) {
15        int slow = n;
16        int fast = getSquareSum(n);
17
18        // Floyd’s cycle detection
19        while (fast != 1 && slow != fast) {
20            slow = getSquareSum(slow);
21            fast = getSquareSum(getSquareSum(fast));
22        }
23
24        return fast == 1;
25    }
26};