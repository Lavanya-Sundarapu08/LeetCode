1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        int n = asteroids.size();
5
6        vector<int> st; 
7        for(int i=0; i < n; i++) {
8             if(asteroids[i] > 0) {
9                st.push_back(asteroids[i]);
10            }
11            else {
12                while(!st.empty() && st.back() > 0 && 
13                      st.back() < abs(asteroids[i])) {
14                    
15                   
16                    st.pop_back();
17                }
18
19                if(!st.empty() && 
20                    st.back() == abs(asteroids[i])) {
21                    
22                    st.pop_back();
23                }
24                else if(st.empty() ||
25                        st.back() < 0){
26                    
27                    st.push_back(asteroids[i]);
28                }
29            }
30        }
31        return st;
32    }
33};