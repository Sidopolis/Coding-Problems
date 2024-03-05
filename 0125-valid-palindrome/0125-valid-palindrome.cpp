class Solution {
public:
    bool isPalindrome(string s)
    {
        string str;
        for (char c : s)
            if (isalnum(c))
                str += tolower(c);
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        return str == rev_str;
    }
};