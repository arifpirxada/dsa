// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
        vector<int> arr(5, 0);
        int result = 0;
        string temp = "00000";
        mp[temp] = -1;

        for (int i = 0; i < s.size(); i++) {
            // if (s[i] == 'a') arr[0] = (arr[0] + 1) % 2;
            // else if (s[i] == 'e') arr[1] = (arr[1] + 1) % 2;
            // else if (s[i] == 'i') arr[2] = (arr[2] + 1) % 2;
            // else if (s[i] == 'o') arr[3] = (arr[3] + 1) % 2;
            // else if (s[i] == 'u') arr[4] = (arr[4] + 1) % 2;
            // use bit manipulation instead 
            if (s[i] == 'a') arr[0] = arr[0] ^ 1;
            else if (s[i] == 'e') arr[1] = arr[1] ^ 1;
            else if (s[i] == 'i') arr[2] = arr[2] ^ 1;
            else if (s[i] == 'o') arr[3] = arr[3] ^ 1;
            else if (s[i] == 'u') arr[4] = arr[4] ^ 1;
            temp = "";
            for (int num : arr) {
                temp += num + '0';
            }
            if (mp.find(temp) != mp.end()) {
                result = max(result, i - mp[temp]);
            } else {
                mp[temp] = i;
            }
        }
        return result;
    }
};

// Using bit masking

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int mask = 0; // 00000
        int result = 0;
        mp[mask] = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') mask = mask ^ (1 << 0);
            else if (s[i] == 'e') mask = mask ^ (1 << 1);
            else if (s[i] == 'i') mask = mask ^ (1 << 2);
            else if (s[i] == 'o') mask = mask ^ (1 << 3);
            else if (s[i] == 'u') mask = mask ^ (1 << 4);

            if (mp.find(mask) != mp.end()) {
                result = max(result, i - mp[mask]);
            } else {
                mp[mask] = i;
            }
        }
        return result;
    }
};