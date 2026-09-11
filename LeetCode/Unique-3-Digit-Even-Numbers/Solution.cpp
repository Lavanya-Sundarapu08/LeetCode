1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        int freq[10]= {};
5
6        for(int d: digits){
7            freq[d]++;
8        }
9
10        int ans = 0;
11        for(int last = 0 ; last <= 8; last+=2){
12            if(freq[last] == 0){
13                continue;
14            }
15
16            freq[last]--;
17
18            for(int first = 1; first<= 9; first++){
19                if(freq[first]== 0){
20                    continue;
21                }
22
23                freq[first]--;
24
25
26                for(int middle = 0 ; middle<=9 ; middle++){
27                    if(freq[middle]>0){
28                        ans++;
29                    }
30
31
32                   
33                }
34
35                freq[first]++;
36            }
37            freq[last]++;
38        }
39        return ans;
40    }
41};