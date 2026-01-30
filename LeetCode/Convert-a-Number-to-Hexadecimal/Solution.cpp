1class Solution {
2public:
3    string toHex(int num) {
4        if(num == 0) return "0";
5
6        unsigned int n = num;
7
8        string hex= "0123456789abcdef";
9        string result= "";
10
11        while(n>0){
12            result =hex[n%16]+result;
13            n/=16;
14        }
15        return result;
16    }
17};