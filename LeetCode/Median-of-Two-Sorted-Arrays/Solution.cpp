1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int n1 = nums1.size();
5        int n2 = nums2.size();
6
7        int n = (n1+n2);
8        int ind2 = n/2;
9        int ind1 = ind2 -1;
10        int i=0;
11        int j=0;
12        int cnt =0;
13
14        int ind1el = -1;
15        int ind2el = -1;
16
17        while(i<n1 && j<n2){
18
19            if(nums1[i]<nums2[j]){
20                if(cnt == ind1)  ind1el = nums1[i];
21                if(cnt == ind2)  ind2el = nums1[i];
22                cnt++;
23                i++;
24            }
25
26            else{
27                if(cnt == ind1)  ind1el = nums2[j];
28                if(cnt == ind2)  ind2el = nums2[j];
29                cnt++;
30                j++;
31            }
32        }
33        while(i<n1){
34            if(cnt == ind1) ind1el=nums1[i];
35            if(cnt == ind2) ind2el=nums1[i];
36            cnt++;
37            i++;
38        }
39
40        while(j<n2){
41            if(cnt == ind1) ind1el=nums2[j];
42            if(cnt == ind2) ind2el=nums2[j];
43            cnt++;
44            j++;
45        }
46
47        if(n%2 == 1){
48            return ind2el;
49        }
50
51        return (double)((double)(ind1el +ind2el))/2.0;
52    }
53};