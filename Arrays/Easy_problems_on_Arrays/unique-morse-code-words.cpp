// https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> mp;
        set<string> s;

        mp['a'] = ".-";
        mp['b'] = "-...";
        mp['c'] = "-.-.";
        mp['d'] = "-..";
        mp['e'] = ".";
        mp['f'] = "..-.";
        mp['g'] = "--.";
        mp['h'] = "....";
        mp['i'] = "..";
        mp['j'] = ".---";
        mp['k'] = "-.-";
        mp['l'] = ".-..";
        mp['m'] = "--";
        mp['n'] = "-.";
        mp['o'] = "---";
        mp['p'] = ".--.";
        mp['q'] = "--.-";
        mp['r'] = ".-.";
        mp['s'] = "...";
        mp['t'] = "-";
        mp['u'] = "..-";
        mp['v'] = "...-";
        mp['w'] = ".--";
        mp['x'] = "-..-";
        mp['y'] = "-.--";
        mp['z'] = "--..";

        for (string word: words) {
            string temp = "";
            for(char c : word) {
                temp += mp[c];
            }
            s.insert(temp);
        }

        return s.size();
    }
};