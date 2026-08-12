1class Solution {
2    public int maxScore(int[] cardPoints, int k) {
3        int n = cardPoints.length;
4
5        int total= 0;
6
7        for(int i =0;i<k;i++){
8            total+= cardPoints[i];
9        }
10
11        int maxPoints = total;
12
13        for(int i =0;i<k;i++){
14            total -= cardPoints[ k - 1 - i];
15
16            total += cardPoints[n - 1 - i];
17
18            maxPoints = Math.max(maxPoints,total);
19        }
20        return maxPoints;
21
22    }
23}