1class Solution {
2    public List<Integer> findMissingElements(int[] nums) {
3        int min = Integer.MAX_VALUE;
4        int max = Integer.MIN_VALUE;
5
6        HashSet<Integer> set = new HashSet<>();
7
8        for (int num : nums) {
9            min = Math.min(min, num);
10            max = Math.max(max, num);
11            set.add(num);
12        }
13
14        List<Integer> ans = new ArrayList<>();
15
16        for (int i = min + 1; i < max; i++) {
17            if (!set.contains(i)) {
18                ans.add(i);
19            }
20        }
21
22        return ans;
23    }
24}