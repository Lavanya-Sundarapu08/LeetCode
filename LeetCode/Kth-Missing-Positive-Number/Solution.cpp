1class Solution {
2public:
3    int findKthPositive(vector<int>& arr, int k) {
4        for(int  i =0 ;i<arr.size(); i++){
5            if(arr[i] <= k) k++;
6            else break;
7        }
8        return k;
9    }
10};