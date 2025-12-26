1class Solution {
2public:
3    string convertToTitle(int columnNumber) {
4        string res= "";
5
6        while(columnNumber>0){
7            columnNumber--;
8            char c= 'A' + (columnNumber%26);
9            res = c+res;
10            columnNumber/= 26;
11        }
12        return res;
13    } 
14};