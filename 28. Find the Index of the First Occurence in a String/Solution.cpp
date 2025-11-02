#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }

        int n = haystack.length();
        int m = needle.length();

        if (m > n) {
            return -1;
        }

        for (int i = 0; i <= n - m; ++i) {
            bool match = true;

            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return i;
            }
        }

        return -1;
    }
};
