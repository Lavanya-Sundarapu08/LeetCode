1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int low = 0;
5        int high = letters.size()- 1;
6        char ans = letters[0];
7
8        while(low<= high){
9            int mid  = low+ (high - low)/2;
10
11            if(letters[mid]>target){
12                ans = letters[mid];
13                high = mid-1;
14            }else{
15                low = mid+1;
16            }
17        }
18        return ans;
19    }
20};