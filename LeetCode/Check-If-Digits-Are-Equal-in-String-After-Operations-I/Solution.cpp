class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
        string temp = "";
        for (size_t i = 0; i < s.size() - 1; i++) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            int sum = (a + b) % 10;  // only keep the last digit
            temp += to_string(sum);
        }
        s = temp;
    }
    // when only 2 digits left
    return (s[0] == s[1]);
    }
};