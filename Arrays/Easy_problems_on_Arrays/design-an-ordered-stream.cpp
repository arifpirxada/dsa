// https://leetcode.com/problems/design-an-ordered-stream/

class OrderedStream {
private:
    map<int, string> mp;
    int ptr;
public:
    OrderedStream(int n) : ptr(1) {}
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        mp[idKey] = value;
        while (mp.count(ptr)) {
            ans.push_back(mp[ptr]);
            ptr++;
        }
        return ans;
    }
};