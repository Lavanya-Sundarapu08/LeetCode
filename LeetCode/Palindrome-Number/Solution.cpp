class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long fd = 0;
        int temp = x;
        while(x > 0){
            int ld = x % 10 ;
            fd = (fd * 10 )+ ld;
            x  = x/ 10;
        }
        if(temp == fd){
            return true;
        }
        else return false;
    }
};