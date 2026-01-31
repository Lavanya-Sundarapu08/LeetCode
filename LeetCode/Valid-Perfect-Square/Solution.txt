1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        long long i=1;
5        while(i*i <= num){
6            if(i*i ==num){
7                return 1;
8            }
9            i++;
10        }
11        return 0;
12    }
13};