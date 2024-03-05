class Solution {
public:
    int strStr(string haystack, string needle) {
       // If needle is an empty string, return 0
        if (needle.empty()) {
            return 0;
        }

        // Find the first occurrence of needle in haystack
        size_t found = haystack.find(needle);

        // If needle is not found in haystack, return -1
        if (found == string::npos) {
            return -1;
        }

        // Otherwise, return the index of the first occurrence
        return found;
    }
};