1class Solution {
2public:
3    string largestOddNumber(string num) {
4        for(int i = num.size()-1;i>=0 ;--i){
5            if((num[i]-'0')%2==1){
6                return num.substr(0,i+1);
7            }
8        }
9    return "";
10    }
11};