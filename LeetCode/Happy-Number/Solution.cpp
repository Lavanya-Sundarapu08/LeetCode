1class Solution {
2public:
3
4    int findSum(int n){
5        int sum =0;
6        while(n >0){
7            int d = n % 10;
8            sum+= d * d;
9            n /= 10;
10        }
11        return sum;
12    }
13    bool solve( int n, unordered_set<int>& seen){
14        if( n == 1) return true;
15
16        if( seen.count(n) ) return false;
17
18        seen.insert(n);
19
20        return solve(findSum(n), seen);
21    }
22    bool isHappy(int n) {
23        unordered_set<int> seen;
24        return solve(n,seen);
25    }
26};