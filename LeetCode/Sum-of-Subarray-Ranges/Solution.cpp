1class Solution {
2public:
3    vector<int> findNSE(vector<int> &arr) {
4        int n = arr.size();
5        vector<int> ans(n);
6        stack<int> st;
7        for(int i = n - 1; i >= 0; i--) {
8            int currEle = arr[i];
9            while(!st.empty() && arr[st.top()] >= currEle){
10                st.pop();
11            }
12            ans[i] = !st.empty() ? st.top() : n;
13            
14            st.push(i);
15        }
16        
17        return ans;
18    }
19    vector<int> findNGE(vector<int> &arr) {
20        
21        int n = arr.size();
22       
23        vector<int> ans(n);
24        
25
26        stack<int> st;
27        
28        for(int i = n - 1; i >= 0; i--) {
29            
30            int currEle = arr[i];
31            
32            while(!st.empty() && arr[st.top()] <= currEle){
33                st.pop();
34            }
35            
36            ans[i] = !st.empty() ? st.top() : n;
37            
38            st.push(i);
39        }
40        
41        return ans;
42    }
43    
44    vector<int> findPSEE(vector<int> &arr) {
45        
46        int n = arr.size();
47        
48        vector<int> ans(n);
49        
50        stack<int> st;
51   
52        for(int i=0; i < n; i++) {
53            
54       
55            int currEle = arr[i];
56            
57            while(!st.empty() && arr[st.top()] > currEle){
58                st.pop();
59            }
60            
61            ans[i] = !st.empty() ? st.top() : -1;
62           
63            st.push(i);
64        }
65
66        return ans;
67    }
68    vector<int> findPGEE(vector<int> &arr) {
69
70        int n = arr.size();
71     
72        vector<int> ans(n);
73        stack<int> st;
74        for(int i=0; i < n; i++) {
75            
76       
77            int currEle = arr[i];
78            
79            while(!st.empty() && arr[st.top()] < currEle){
80                st.pop();
81            }
82            
83            ans[i] = !st.empty() ? st.top() : -1;
84            
85            st.push(i);
86        }
87       
88        return ans;
89    }
90    long long subArrayRanges(vector<int>& nums) {
91
92    vector<int> nse = findNSE(nums);
93    vector<int> psee = findPSEE(nums);
94
95    vector<int> nge = findNGE(nums);
96    vector<int> pgee = findPGEE(nums);
97
98    int n = nums.size();
99
100    long long minSum = 0;
101    long long maxSum = 0;
102
103    // Minimum contribution
104    for(int i = 0; i < n; i++) {
105        long long left = i - psee[i];
106        long long right = nse[i] - i;
107
108        long long freq = left * right;
109        minSum += freq * nums[i];
110    }
111
112    // Maximum contribution
113    for(int i = 0; i < n; i++) {
114        long long left = i - pgee[i];
115        long long right = nge[i] - i;
116
117        long long freq = left * right;
118        maxSum += freq * nums[i];
119    }
120
121    return maxSum - minSum;
122    }
123};