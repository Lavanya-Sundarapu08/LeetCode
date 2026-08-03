1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        if(strs.empty()) return "";
5        int n = strs.size();
6        sort(strs.begin(),strs.end());
7        string first = strs.front();
8        string second = strs.back();
9        int i = 0;
10        while(i<first.size() && i<second.size() && first[i]==second[i]){
11            i++;
12        }
13        return first.substr(0,i);
14    }
15};