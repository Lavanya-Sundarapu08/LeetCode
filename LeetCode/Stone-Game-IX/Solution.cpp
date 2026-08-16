1class Solution {
2public:
3    bool stoneGameIX(vector<int>& stones) {
4        int count[3] = {0, 0, 0};
5
6        for(int stone : stones){
7            count[stone % 3]++;
8        }
9
10        if(count[0] % 2 == 0){
11            return count[1] >0 && count[2] > 0;
12        }
13        return abs(count[1] - count[2]) > 2;
14    }
15};