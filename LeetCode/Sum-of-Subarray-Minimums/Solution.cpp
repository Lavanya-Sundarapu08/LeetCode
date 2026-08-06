1class Solution {
2public:
3
4    vector<int> findNSE(vector<int> &arr){
5        int n = arr.size();
6        vector<int> ans(n);
7        stack<int> st;
8
9        for(int i = n-1; i>= 0 ; i--){
10
11            int currEle = arr[i];
12
13            while(!st.empty() && arr[st.top()] >=arr[i]){
14                st.pop();
15            }
16            ans[i] = !st.empty() ? st.top() : n;
17
18            st.push(i);
19        }
20        return ans;
21    }
22    vector<int> findPSEE(vector<int> &arr){
23        int n = arr.size();
24        vector<int> ans(n);
25        stack<int> st;
26
27        for(int i = 0; i <= n-1 ; i++){
28
29            int currEle = arr[i];
30
31            while(!st.empty() && arr[st.top()] > arr[i]){
32                st.pop();
33            }
34            ans[i] = !st.empty() ? st.top() : -1;
35
36            st.push(i);
37        }
38        return ans;
39    }
40    int sumSubarrayMins(vector<int>& arr) {
41        vector<int> nse = findNSE(arr);
42        
43        vector<int> psee =findPSEE(arr);
44
45        int n = arr.size();
46        int mod = 1e9 + 7;
47
48        int sum =0;
49        for(int i=0; i < n; i++){
50            int left = i - psee[i];
51            int right = nse[i] - i;
52
53            long long freq = left*right*1LL;
54
55            int val = (freq*arr[i]*1LL) % mod;
56
57            sum = (sum + val) % mod;
58        }
59        return sum;
60    }
61};