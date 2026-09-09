1class Solution {
2public:
3    long long countCommas(long long n) {
4        
5        long long ans = 0;
6
7        long long start = 1000;
8        long long commas = 1;
9
10        while(start <= n){
11            long long end = min(n, start*1000-1);
12            ans+= (end - start+1)* commas;
13            start*= 1000;
14            commas++;
15        }
16        return ans;
17    }
18};