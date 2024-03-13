class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char_word_map;
        unordered_map<string, char> word_char_map;
        stringstream str(s);
        string word;
        int i = 0;
        while(str >> word){
            if(i == pattern.size()) return false; // More words in 's' than characters in 'pattern'
            char c = pattern[i];
            if(char_word_map.count(c) && char_word_map[c] != word) return false; // Mismatch in pattern to word mapping
            if(word_char_map.count(word) && word_char_map[word] != c) return false; // Mismatch in word to pattern mapping
            char_word_map[c] = word;
            word_char_map[word] = c;
            i++;
        }
        return i == pattern.size(); // Check if there are more characters left in 'pattern'
    }
};