1class Solution {
2public:
3    bool possible(vector<int>bloomDay, int day ,int m,int k){
4        int cnt =0;
5        int noOfB = 0;
6        for(int i =0;i<bloomDay.size();i++){
7            if(bloomDay[i]<= day){
8                cnt++;
9            }else{
10                noOfB += (cnt/k);
11                cnt =0;
12            }
13        }
14        noOfB += (cnt/k);
15        return noOfB >= m;
16    };
17    int minDays(vector<int>& bloomDay, int m, int k) {
18        long long value = m * 1LL * k * 1LL;
19
20        if(value > bloomDay.size()) return -1;
21
22        int mini = INT_MAX, maxi = INT_MIN;
23        for(int i =0;i<bloomDay.size();i++){
24            mini = min(mini,bloomDay[i]);
25            maxi = max(maxi,bloomDay[i]);
26        }
27        int low = mini;
28        int high = maxi;
29        while(low<=high){
30            int mid = (low+high)/2;
31            if(possible(bloomDay,mid,m,k)){
32                high = mid-1;
33            }else{
34                low = mid+1;
35            }
36        }
37        return low;
38    }
39};