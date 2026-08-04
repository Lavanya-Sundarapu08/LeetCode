1class Solution {
2    public List<List<String>> groupAnagrams(String[] strs) {
3
4        HashMap<String, List<String>> map = new HashMap<>();
5
6        for (String s : strs) {
7
8            char[] arr = s.toCharArray();
9            Arrays.sort(arr);
10
11            String key = new String(arr);
12
13            if (!map.containsKey(key)) {
14                map.put(key, new ArrayList<>());
15            }
16
17            map.get(key).add(s);
18        }
19
20        return new ArrayList<>(map.values());
21    }
22};