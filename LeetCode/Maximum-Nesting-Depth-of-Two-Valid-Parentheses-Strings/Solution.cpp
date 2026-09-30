1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        vector<int> ans;
5        int depth = 0;
6
7        for(char c : seq){
8            if(c == '('){
9                depth++;
10                ans.push_back(depth % 2);
11            }else{
12                ans.push_back(depth % 2);
13                depth--;
14            }
15        }
16        return ans;
17    }
18};