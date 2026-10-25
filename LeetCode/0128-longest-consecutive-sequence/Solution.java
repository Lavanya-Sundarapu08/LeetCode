class Solution {
    public int longestConsecutive(int[] nums) {
         HashSet<Integer> set = new HashSet<>();

        // Store all elements in the HashSet
        for (int num : nums) {
            set.add(num);
        }

        int longest = 0;

        for (int num : set) {
            // Start counting only if num is the start of a sequence
            if (!set.contains(num - 1)) {
                int current = num;
                int count = 1;

                while (set.contains(current + 1)) {
                    current++;
                    count++;
                }

                longest = Math.max(longest, count);
            }
        }

        return longest;
    }
}