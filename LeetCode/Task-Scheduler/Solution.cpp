1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        unordered_map<char,int> freq;
5
6        for(char task: tasks){
7            freq[task]++;
8        }
9
10        priority_queue<int> maxHeap;
11
12        for(auto& entry: freq){
13            maxHeap.push(entry.second);//A-> 3
14        }
15
16        int time = 0;
17        while(!maxHeap.empty()){
18            vector<int> temp; // A->3,B->3  = [3,3]
19
20            int cycle = n+1;
21
22            int i =0;
23
24            while(i < cycle && !maxHeap.empty()){
25                int cnt = maxHeap.top();// A->3
26                maxHeap.pop();
27
28                cnt--; //A-> 2
29
30                if(cnt > 0){
31                    temp.push_back(cnt); // A->2
32                }
33
34                time++;
35                i++;
36                //completed firat cycle
37            }//again second cycle
38
39            for(int val : temp){
40                maxHeap.push(val);//push [2,2]
41            }
42
43            if(maxHeap.empty()) break;
44
45            time += (cycle - i);
46        }
47        return time;
48    }
49};